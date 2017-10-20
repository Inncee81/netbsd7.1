$NetBSD$

--- lib/auth_krb5.c.orig	2012-12-01 19:57:54.000000000 +0000
+++ lib/auth_krb5.c
@@ -199,6 +199,14 @@ static void myfreestate(struct auth_stat
     free(auth_state);
 }
 
+static char *mycanonuser(struct auth_state *auth_state)
+{
+    if (auth_state)
+       return auth_state->userid;
+
+    return NULL;
+}
+
 #else /* HAVE_GSSAPI_H */
 
 static int mymemberof(
@@ -230,6 +238,13 @@ static void myfreestate(
 	fatal("Authentication mechanism (krb5) not compiled in", EC_CONFIG);
 }
 
+static char *mycanonuser(
+    struct auth_state *auth_state __attribute__((unused)))
+{
+        fatal("Authentication mechanism (krb5) not compiled in", EC_CONFIG);
+	return NULL;
+}
+
 #endif
 
 struct auth_mech auth_krb5 = 
@@ -240,4 +255,5 @@ struct auth_mech auth_krb5 = 
     &mymemberof,
     &mynewstate,
     &myfreestate,
+    &mycanonuser,
 };
