$NetBSD$

--- imap/imapd.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ imap/imapd.c
@@ -330,6 +330,7 @@ enum {
 void motd_file(int fd);
 void shut_down(int code);
 void fatal(const char *s, int code);
+void autocreate_inbox(void);
 
 void cmdloop(void);
 void cmd_login(char *tag, char *user);
@@ -2167,8 +2168,47 @@ static void authentication_success(void)
     mboxname_hiersep_tointernal(&imapd_namespace, imapd_userid,
 				config_virtdomains ?
 				strcspn(imapd_userid, "@") : 0);
+
+    autocreate_inbox();
+}
+
+/*
+ * Autocreate Inbox and subfolders upon login
+ */
+void autocreate_inbox()
+{
+    char inboxname[MAX_MAILBOX_NAME+1];
+    int autocreatequota;
+    int r;
+ 
+    /*
+     * Exlude admin's accounts
+     */
+    if (imapd_userisadmin || imapd_userisproxyadmin)
+        return;
+ 
+    /*
+     * Exclude anonymous
+     */
+    if (!strcmp(imapd_userid, "anonymous"))
+        return;
+ 
+    if ((autocreatequota = config_getint(IMAPOPT_AUTOCREATEQUOTA))) {
+        /* This is actyally not required
+           as long as the lenght of userid is ok */
+           r = (*imapd_namespace.mboxname_tointernal) (&imapd_namespace,
+                                      "INBOX", imapd_userid, inboxname);
+           if (!r)
+               r = mboxlist_lookup(inboxname, NULL, NULL);
+ 
+           if (r == IMAP_MAILBOX_NONEXISTENT) {
+                mboxlist_autocreateinbox(&imapd_namespace, imapd_userid,
+                         imapd_authstate, inboxname, autocreatequota);
+	   }
+     }
 }
 
+
 /*
  * Perform a LOGIN command
  */
@@ -6005,6 +6045,8 @@ void getlistargs(char *tag, struct lista
 	goto freeargs;
     }
 
+    autocreate_inbox();
+
     return;
 
   freeargs:
