$NetBSD$

--- imap/pop3d.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ imap/pop3d.c
@@ -181,6 +181,8 @@ static void bitpipe(void);
 static char popd_apop_chal[45 + MAXHOSTNAMELEN + 1]; /* <rand.time@hostname> */
 static void cmd_apop(char *response);
 
+static int autocreate_inbox(char *inboxname, char *userid);
+
 static void cmd_auth(char *arg);
 static void cmd_capa(void);
 static void cmd_pass(char *pass);
@@ -1401,6 +1403,7 @@ void cmd_user(char *user)
 	popd_userid = xstrdup(userbuf);
 	prot_printf(popd_out, "+OK Name is a valid mailbox\r\n");
     }
+
 }
 
 void cmd_pass(char *pass)
@@ -1718,6 +1721,43 @@ void cmd_auth(char *arg)
 }
 
 /*
+ * Autocreate Inbox and subfolders upon login
+ */
+int autocreate_inbox(char *inboxname, char *auth_userid)
+{
+    struct auth_state *auth_state;
+    int autocreatequota;
+    int r;
+
+    if (inboxname == NULL || auth_userid == NULL)
+	    return IMAP_MAILBOX_NONEXISTENT;
+    
+    /*
+     * Exclude anonymous
+     */
+    if (!strcmp(popd_userid, "anonymous"))
+        return IMAP_MAILBOX_NONEXISTENT;
+
+    /*
+     * Check for autocreatequota
+     */
+    if (!(autocreatequota = config_getint(IMAPOPT_AUTOCREATEQUOTA)))
+        return IMAP_MAILBOX_NONEXISTENT;
+
+    /*
+     * Exclude admin's accounts
+     */
+     auth_state = auth_newstate(popd_userid);
+     if (global_authisa(auth_state, IMAPOPT_ADMINS))
+          return IMAP_MAILBOX_NONEXISTENT;
+
+     r = mboxlist_autocreateinbox(&popd_namespace, auth_userid,
+                         auth_state, inboxname, autocreatequota);
+     return r;
+}
+
+
+/*
  * Complete the login process by opening and locking the user's inbox
  */
 int openinbox(void)
@@ -1746,6 +1786,12 @@ int openinbox(void)
 					      userid, inboxname);
 
     if (!r) r = mboxlist_lookup(inboxname, &mbentry, NULL);
+
+    /* Try once again after autocreate_inbox */
+    if (r == IMAP_MAILBOX_NONEXISTENT && 
+      !(r = autocreate_inbox(inboxname, userid)))
+	r = mboxlist_lookup(inboxname, &mbentry, NULL);
+
     if (!r && (config_popuseacl = config_getswitch(IMAPOPT_POPUSEACL)) &&
 	(!mbentry.acl ||
 	 !((myrights = cyrus_acl_myrights(popd_authstate, mbentry.acl)) & ACL_READ))) {
