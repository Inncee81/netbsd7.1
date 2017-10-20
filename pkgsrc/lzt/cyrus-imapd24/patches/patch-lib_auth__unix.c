$NetBSD$

--- lib/auth_unix.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ lib/auth_unix.c
@@ -315,6 +315,16 @@ struct auth_state *auth_state;
     free((char *)auth_state);
 }
 
+static char *mycanonuser(auth_state)
+    struct auth_state *auth_state;
+{
+    if (auth_state)
+         return auth_state->userid;
+
+    return NULL;
+}
+
+
 
 struct auth_mech auth_unix = 
 {
@@ -324,4 +334,5 @@ struct auth_mech auth_unix = 
     &mymemberof,
     &mynewstate,
     &myfreestate,
+    &mycanonuser,
 };
