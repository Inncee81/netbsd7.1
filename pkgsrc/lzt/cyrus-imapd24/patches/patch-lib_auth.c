$NetBSD$

--- lib/auth.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ lib/auth.c
@@ -118,3 +118,11 @@ struct auth_state *auth_state;
 
     auth->freestate(auth_state);
 }
+
+char *auth_canonuser(struct auth_state *auth_state)
+{
+    struct auth_mech *auth = auth_fromname();
+
+    return auth->auth_canonuser(auth_state);
+}
+
