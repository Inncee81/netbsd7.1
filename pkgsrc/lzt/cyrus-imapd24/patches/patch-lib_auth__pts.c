$NetBSD$

--- lib/auth_pts.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ lib/auth_pts.c
@@ -521,6 +521,14 @@ static void myfreestate(struct auth_stat
     free(auth_state);
 }
 
+static char *mycanonuser(struct auth_state *auth_state)
+{
+    if (auth_state)
+       return auth_state->userid.id;
+
+    return NULL;
+}
+
 struct auth_mech auth_pts = 
 {
     "pts",		/* name */
@@ -529,4 +537,5 @@ struct auth_mech auth_pts = 
     &mymemberof,
     &mynewstate,
     &myfreestate,
+    &mycanonuser,
 };
