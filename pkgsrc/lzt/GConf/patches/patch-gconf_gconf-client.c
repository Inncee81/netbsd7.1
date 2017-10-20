$NetBSD$

--- gconf/gconf-client.c.orig	2010-09-10 08:14:17.000000000 +0000
+++ gconf/gconf-client.c
@@ -175,6 +175,7 @@ gconf_client_get_type (void)
         (GInstanceInitFunc) gconf_client_init
       };
 
+      g_type_init();
       client_type = g_type_register_static (G_TYPE_OBJECT,
                                             "GConfClient",
                                             &client_info,
