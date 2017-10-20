$NetBSD$

--- imap/mboxlist.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ imap/mboxlist.c
@@ -85,6 +85,12 @@
 #include "quota.h"
 #include "sync_log.h"
 
+#ifdef USE_SIEVE
+extern int autoadd_sieve(char *userid, 
+		const char *source_script);
+#endif
+
+
 #define DB config_mboxlist_db
 #define SUBDB config_subscription_db
 
@@ -101,6 +107,19 @@ static int mboxlist_rmquota(const char *
 			    void *rock);
 static int mboxlist_changequota(const char *name, int matchlen, int maycreate,
 				void *rock);
+static int mboxlist_autosubscribe_sharedfolders(struct namespace *namespace,
+				char *userid, char *auth_userid,
+				struct auth_state *auth_state);
+
+/*
+ * Struct needed to be passed as void *rock to
+ * mboxlist_autochangesub();
+ */
+struct changesub_rock_st {
+	char *userid;
+	char *auth_userid;
+	struct auth_state *auth_state;
+};
 
 char *mboxlist_makeentry(int mbtype, const char *part, const char *acl)
 {
@@ -3149,3 +3168,349 @@ mboxlist_count_inferiors(const char *mai
 
     return(count);
 }
+
+/*
+ * Automatically subscribe user to *ALL* shared folders,
+ * one has permissions to be subscribed to.
+ * INBOX subfolders are excluded.
+ */
+static int mboxlist_autochangesub(char *name, int matchlen, int maycreate,
+                        void *rock) {
+
+  struct changesub_rock_st *changesub_rock = (struct changesub_rock_st *) rock;
+  char *userid = changesub_rock->userid;
+  char *auth_userid = changesub_rock->auth_userid;
+  struct auth_state *auth_state = changesub_rock->auth_state;
+  int r;
+
+
+  if((strlen(name) == 5 && !strncmp(name, "INBOX", 5)) || /* Exclude INBOX */
+     (strlen(name) > 5  && !strncmp(name, "INBOX.",6)) || /* Exclude INBOX subfolders */
+     (strlen(name) > 4  && !strncmp(name, "user.", 5)))   /* Exclude other users' folders */
+	  return 0;
+
+     
+  r = mboxlist_changesub(name, userid, auth_state, 1, 0);
+
+  if (r) {
+      syslog(LOG_WARNING,
+             "autosubscribe: User %s to folder %s, subscription failed: %s",
+             auth_userid, name, error_message(r));
+  } else {
+      syslog(LOG_NOTICE,
+             "autosubscribe: User %s to folder %s, subscription succeeded",
+             auth_userid, name);
+  }
+
+  return 0;
+}
+
+#define SEP '|'
+
+/*
+ * Automatically subscribe user to a shared folder.
+ * Subscription is done successfully, if the shared
+ * folder exists and the user has the necessary 
+ * permissions.
+ */
+static int mboxlist_autosubscribe_sharedfolders(struct namespace *namespace,
+                        char *userid, char *auth_userid,
+                        struct auth_state *auth_state) {
+        
+    const char *sub ;
+    char *p, *q, *next_sub;
+    char folder[MAX_MAILBOX_NAME+1], name[MAX_MAILBOX_NAME+1], mailboxname[MAX_MAILBOX_NAME+1];
+    int len;
+    int r = 0;
+    int subscribe_all_sharedfolders = 0;
+
+    subscribe_all_sharedfolders = config_getswitch(IMAPOPT_AUTOSUBSCRIBE_ALL_SHAREDFOLDERS);
+
+    /*
+     * If subscribeallsharedfolders is set to yes in imapd.conf, then
+     * subscribe user to every shared folder one has the apropriate 
+     * permissions.
+     */
+    if(subscribe_all_sharedfolders) {
+       char pattern[MAX_MAILBOX_PATH+1];
+       struct changesub_rock_st changesub_rock;
+
+       strcpy(pattern, "*");
+       changesub_rock.userid = userid;
+       changesub_rock.auth_userid = auth_userid;
+       changesub_rock.auth_state = auth_state;
+
+       r = mboxlist_findall(namespace, pattern, 0, userid,
+                            auth_state, mboxlist_autochangesub, &changesub_rock);
+
+       return r;
+    }
+
+    if ((sub=config_getstring(IMAPOPT_AUTOSUBSCRIBESHAREDFOLDERS)) == NULL)
+       return r;
+
+    next_sub = (char *) sub;
+    while (*next_sub) {
+        for (p = next_sub ; isspace((int) *p) || *p == SEP ; p++);
+        for (next_sub = p ; *next_sub && *next_sub != SEP ; next_sub++);
+        for (q = next_sub ; q > p && (isspace((int) *q) || *q == SEP || !*q) ; q--);
+        if (!*p ) continue;
+
+        len = q - p + 1;
+        /* Check for folder length */
+        if (len  > sizeof(folder)-1)
+                continue;
+
+        if (!r) {
+                strncpy(folder, p, len);
+                folder[len] = '\0';
+
+               strlcpy(name, namespace->prefix[NAMESPACE_SHARED], sizeof(name));
+               len = strlcat(name, folder, sizeof(name));
+
+               r = (namespace->mboxname_tointernal) (namespace, name, userid,
+                                                                  mailboxname);
+       }
+                                                                  
+        if (!r)
+               r = mboxlist_changesub(mailboxname, userid, auth_state, 1, 0);
+
+        if (!r) {
+                syslog(LOG_NOTICE, "autosubscribe: User %s to %s succeeded", 
+                       userid, folder);
+        } else {
+                syslog(LOG_WARNING, "autosubscribe: User %s to %s failed: %s", 
+                       userid, folder, error_message(r));
+                r = 0;
+        }
+    }
+
+    return r;
+}
+
+
+
+int mboxlist_autocreateinbox(struct namespace *namespace,
+                        char *userid,
+                        struct auth_state *auth_state,
+                        char *mailboxname, int autocreatequota) {
+    char name [MAX_MAILBOX_NAME+1];
+    char folder [MAX_MAILBOX_NAME+1];
+    char *auth_userid = NULL;
+    char *partition = NULL;
+    const char *crt;
+    const char *sub;
+    char *p, *q, *next_crt, *next_sub;
+    int len;
+    int r = 0;
+    int numcrt = 0;
+    int numsub = 0;
+#ifdef USE_SIEVE
+    const char *source_script;
+#endif
+
+
+
+    auth_userid = auth_canonuser(auth_state);
+    if (auth_userid == NULL) {
+         /*
+          * Couldn't get cannon userid
+          */
+          syslog(LOG_ERR,
+                 "autocreateinbox: Could not get canonified userid for user %s", userid);
+          return IMAP_PARTITION_UNKNOWN;
+    }
+
+    /* Added this for debug information. */
+    syslog(LOG_DEBUG, "autocreateinbox: autocreate inbox for user %s was called", auth_userid);
+
+   /*
+    * While this is not needed for admins
+    * and imap_admins accounts, it would be
+    * better to separate *all* admins and
+    * proxyservers from normal accounts
+    * (accounts that have mailboxes).
+    * UOA Specific note(1): Even if we do not
+    * exclude these servers-classes here,
+    * UOA specific code, will neither return
+    * role, nor create INBOX, because none of these
+    * administrative accounts belong to  the
+    * mailRecipient objectclass, or have imapPartition.
+    * UOA Specific note(2): Another good reason for doing
+    * this, is to prevent the code, from getting into
+    * cyrus_ldap.c because of the continues MSA logins to LMTPd.
+    */
+
+   /*
+    * admins and the coresponding imap
+    * service, had already been excluded.
+    */
+
+   /*
+    * Do we really need group membership
+    * for admins or service_admins?
+    */
+    if (global_authisa(auth_state, IMAPOPT_ADMINS)) return 0;
+
+   /*
+    * Do we really need group membership
+    * for proxyservers?
+    */
+    if (global_authisa(auth_state, IMAPOPT_PROXYSERVERS)) return 0;
+
+    /* 
+     * Check if user belongs to the autocreate_users group. This option
+     * controls for whom the mailbox may be automatically created. Default
+     * value for this option is 'anyone'. So, if not declared, all mailboxes
+     * will be created.
+     */
+    if (!global_authisa(auth_state, IMAPOPT_AUTOCREATE_USERS)) {
+	    syslog(LOG_DEBUG, "autocreateinbox: User %s does not belong to the autocreate_users. No mailbox is created",
+			    auth_userid);
+	    return IMAP_MAILBOX_NONEXISTENT;
+    }
+
+#if 0
+        /*
+         * Get Partition info or return.
+         * (Here you should propably use
+         * you own "get_partition(char *userid)"
+         * function. Otherwise all new INBOXes will be
+         * created into whatever partition has been declared
+         * as default in your imapd.conf)
+         */
+
+        partition = get_partition(userid);
+        if (partition == NULL) {
+            /*
+             * Couldn't get partition info
+             */
+            syslog(LOG_ERR,
+                   "Could not get imapPartition info for user %s", userid);
+            return IMAP_PARTITION_UNKNOWN;
+        }
+#endif
+
+    r = mboxlist_createmailbox(mailboxname, 0, NULL,
+                                      1, userid, auth_state, 0, 0, 0);
+
+    if (!r && autocreatequota > 0)
+        r = mboxlist_setquota(mailboxname, autocreatequota, 0);
+
+    if (!r)
+        r = mboxlist_changesub(mailboxname, userid,
+                              auth_state, 1, 1);
+
+    if (!r) {
+       syslog(LOG_NOTICE, "autocreateinbox: User %s, INBOX was successfully created in partition %s", 
+               auth_userid, partition == NULL ? "default" : partition);
+    } else {
+       syslog(LOG_ERR, "autocreateinbox: User %s, INBOX failed. %s", 
+               auth_userid, error_message(r));
+    }
+
+#if 0
+    /* Allocated from get_partition, and not needed any more */
+    free_partition(partition);
+#endif
+
+    if (r) return r;
+
+    /* INBOX's subfolders */
+    if ((crt=config_getstring(IMAPOPT_AUTOCREATEINBOXFOLDERS)))
+        sub=config_getstring(IMAPOPT_AUTOSUBSCRIBEINBOXFOLDERS);
+
+    /* Roll through crt */
+    next_crt = (char *) crt;
+    while (next_crt!=NULL && *next_crt) {
+          for (p = next_crt ; isspace((int) *p) || *p == SEP ; p++);
+          for (next_crt = p ; *next_crt && *next_crt != SEP ; next_crt++);
+          for (q = next_crt ; q > p && (isspace((int) *q) || *q == SEP || !*q); q--);
+
+          if (!*p) continue;
+
+          len = q - p + 1;
+
+          /* First time we check for length */
+          if (len > sizeof(folder) - 5)
+              r = IMAP_MAILBOX_BADNAME;
+
+          if (!r) {
+                  strncpy(folder, p, len);
+                  folder[len] = '\0';
+
+                  strlcpy(name, namespace->prefix[NAMESPACE_INBOX], sizeof(name));
+                  len = strlcat(name, folder, sizeof(name));
+          }
+
+          if (!r)
+            r = (namespace->mboxname_tointernal) (namespace, name, userid,
+                                                 mailboxname);
+          if (!r)
+             r = mboxlist_createmailbox(mailboxname, 0, NULL,
+                                            1, userid, auth_state, 0, 0, 0);
+
+          if (!r) {
+            numcrt++;
+            syslog(LOG_NOTICE, "autocreateinbox: User %s, subfolder %s creation succeeded.", 
+               auth_userid, name);
+         } else {
+             syslog(LOG_WARNING, "autocreateinbox: User %s, subfolder %s creation failed. %s", 
+               auth_userid, name, error_message(r));
+             r=0;
+             continue;
+          }
+
+          /* Roll through sub */
+          next_sub = (char *) sub;
+          while (next_sub!=NULL && *next_sub) {
+                for (p = next_sub ; isspace((int) *p) || *p == SEP ; p++);
+                for (next_sub = p ; *next_sub && *next_sub != SEP ; next_sub++);
+                for (q = next_sub ; q > p && (isspace((int) *q) || *q == SEP || !*q) ; q--);
+                if (!*p ) continue;
+
+                len = q - p + 1;
+
+                if (len != strlen(folder) || strncmp(folder, p, len))
+                    continue;
+
+                r = mboxlist_changesub(mailboxname, userid, auth_state, 1, 1);
+
+               if (!r) {
+                   numsub++;
+                   syslog(LOG_NOTICE,"autocreateinbox: User %s, subscription to %s succeeded",
+                       auth_userid, name);
+               } else
+                    syslog(LOG_WARNING, "autocreateinbox: User %s, subscription to  %s failed. %s",
+                       auth_userid, name, error_message(r));
+
+                break;
+         }
+    }
+
+    if (crt!=NULL && *crt)
+       syslog(LOG_INFO, "User %s, Inbox subfolders, created %d, subscribed %d", 
+               auth_userid, numcrt, numsub);
+
+    /*
+     * Check if shared folders are available for subscription.
+     */
+    mboxlist_autosubscribe_sharedfolders(namespace, userid, auth_userid, auth_state);
+
+#ifdef USE_SIEVE
+    /*
+     * Here the autocreate sieve script feature is iniated from.
+     */
+    source_script = config_getstring(IMAPOPT_AUTOCREATE_SIEVE_SCRIPT);
+ 
+    if (source_script) {
+        if (!autoadd_sieve(userid, source_script))
+            syslog(LOG_NOTICE, "autocreate_sieve: User %s, default sieve script creation succeeded", auth_userid);
+        else
+            syslog(LOG_WARNING, "autocreate_sieve: User %s, default sieve script creation failed", auth_userid);
+    }
+#endif
+
+    return r;
+}
+
