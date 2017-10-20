$NetBSD$

--- lib/auth.h.orig	2012-12-01 19:57:54.000000000 +0000
+++ lib/auth.h
@@ -55,6 +55,7 @@ struct auth_mech {
              const char *identifier);
     struct auth_state *(*newstate)(const char *identifier);
     void (*freestate)(struct auth_state *auth_state);
+    char *(*auth_canonuser)(struct auth_state *auth_state);
 };
 
 extern struct auth_mech *auth_mechs[];
@@ -77,5 +78,6 @@ int auth_memberof(struct auth_state *aut
  	 const char *identifier);
 struct auth_state *auth_newstate(const char *identifier);
 void auth_freestate(struct auth_state *auth_state);
+char *auth_canonuser(struct auth_state *auth_state);
 
 #endif /* INCLUDED_AUTH_H */
