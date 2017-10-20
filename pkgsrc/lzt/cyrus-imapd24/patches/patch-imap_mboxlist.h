$NetBSD$

--- imap/mboxlist.h.orig	2012-12-01 19:57:54.000000000 +0000
+++ imap/mboxlist.h
@@ -217,4 +217,9 @@ int mboxlist_count_inferiors(const char 
 			     const char *userid,
 			     struct auth_state *authstate);
 
+int mboxlist_autocreateinbox(struct namespace *namespace,char *userid,
+				struct auth_state *auth_state, char *mailboxname, 
+			       int autocreatequota);
+
+
 #endif
