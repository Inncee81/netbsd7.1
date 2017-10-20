$NetBSD$

--- lib/auth_krb.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ lib/auth_krb.c
@@ -341,6 +341,15 @@ struct auth_state *auth_state;
     free((char *)auth_state);
 }
 
+static char *mycanonuser(struct auth_state *auth_state)
+{
+    if (auth_state)
+       return auth_state->userid;
+
+    return NULL;
+}
+
+
 #else /* HAVE_KRB */
 
 static int mymemberof(
@@ -372,6 +381,13 @@ static void myfreestate(
 	fatal("Authentication mechanism (krb) not compiled in", EC_CONFIG);
 }
 
+static char *mycanonuser(
+    struct auth_state *auth_state __attribute__((unused)))
+{
+        fatal("Authentication mechanism (krb) not compiled in", EC_CONFIG);
+}
+
+
 #endif
 
 struct auth_mech auth_krb = 
@@ -382,4 +398,5 @@ struct auth_mech auth_krb = 
     &mymemberof,
     &mynewstate,
     &myfreestate,
+    &mycanonuser,
 };
