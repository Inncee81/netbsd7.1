$NetBSD$

--- imap/lmtpd.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ imap/lmtpd.c
@@ -119,6 +119,8 @@ void shut_down(int code);
 static FILE *spoolfile(message_data_t *msgdata);
 static void removespool(message_data_t *msgdata);
 
+static int autocreate_inbox(const char *user, const char *domain);
+
 /* current namespace */
 static struct namespace lmtpd_namespace;
 
@@ -984,6 +986,86 @@ void shut_down(int code)
     exit(code);
 }
 
+
+/*
+ * Autocreate Inbox and subfolders upon login
+ */
+int autocreate_inbox(const char *user, const char *domain)
+{
+    struct auth_state *auth_state;
+    char inboxname[MAX_MAILBOX_NAME+1];
+    char *rcpt_userid = NULL;
+    int autocreatequota;
+    int r = 0;
+
+    if (user == NULL)
+          return IMAP_MAILBOX_NONEXISTENT;
+
+    if (domain != NULL) {
+	int k;
+	
+	rcpt_userid = (char *) xmalloc((strlen(user) + strlen(domain) + 2) * sizeof(char));
+	k = strlcpy(rcpt_userid, user, strlen(user) + 1);
+  	*(rcpt_userid + k) = '@';
+       strlcpy(rcpt_userid + k + 1, domain, strlen(domain) + 1);
+    } else {
+	rcpt_userid = (char *) user;
+    }
+
+
+    /*
+     * Exclude anonymous
+     */
+    if (!strcmp(rcpt_userid, "anonymous")) {
+	if (rcpt_userid != user) {
+	    free(rcpt_userid);
+	}
+
+        return IMAP_MAILBOX_NONEXISTENT;
+    }
+    
+    /*
+     * Check for autocreatequota and createonpost
+     */
+    if (!(autocreatequota = config_getint(IMAPOPT_AUTOCREATEQUOTA)) ||
+        !(config_getswitch(IMAPOPT_CREATEONPOST))) {
+	    
+	if (rcpt_userid != user) {
+	    free(rcpt_userid);
+	}
+	
+        return IMAP_MAILBOX_NONEXISTENT;
+     }
+
+
+    /*
+     * Exclude admin's accounts
+     */
+     auth_state = auth_newstate(rcpt_userid);
+     
+     if (global_authisa(auth_state, IMAPOPT_ADMINS)) {
+	if (rcpt_userid != user) {
+	    free(rcpt_userid);
+	}
+
+        return IMAP_MAILBOX_NONEXISTENT;
+     }
+     
+     r = (*lmtpd_namespace.mboxname_tointernal) (&lmtpd_namespace,
+                                "INBOX", rcpt_userid, inboxname);
+     
+     if (!r)
+ 	r = mboxlist_autocreateinbox(&lmtpd_namespace, rcpt_userid,
+                         auth_state, inboxname, autocreatequota);
+     
+     if (rcpt_userid != user) {
+	free(rcpt_userid);
+     }
+       
+     return r;
+}
+
+
 static int verify_user(const char *user, const char *domain, char *mailbox,
 		       quota_t quotacheck, struct auth_state *authstate)
 {
@@ -1027,6 +1109,15 @@ static int verify_user(const char *user,
 	 */
 	r = mlookup(namebuf, &server, &acl, NULL);
 
+	/* If user mailbox does not exist, then invoke autocreate inbox function */
+	if (r == IMAP_MAILBOX_NONEXISTENT) {
+	    r = autocreate_inbox(user, domain);
+
+	    /* Try to locate the mailbox again */
+	    if (!r)
+		r = mlookup(namebuf, &server, &acl, NULL);
+	}
+
 	if (r == IMAP_MAILBOX_NONEXISTENT && !user &&
 	    config_getswitch(IMAPOPT_LMTP_FUZZY_MAILBOX_MATCH) &&
 	    /* see if we have a mailbox whose name is close */
@@ -1053,6 +1144,7 @@ static int verify_user(const char *user,
 			     aclcheck, (quotacheck < 0)
 			     || config_getswitch(IMAPOPT_LMTP_STRICT_QUOTA) ?
 			     quotacheck : 0);
+
 	}
     }
 
