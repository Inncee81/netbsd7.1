$NetBSD$

--- plug-ins/script-fu/script-fu-server.c.orig	2015-08-20 22:57:29.000000000 +0000
+++ plug-ins/script-fu/script-fu-server.c
@@ -469,7 +469,11 @@ server_start (const gchar *listen_ip,
   const gchar     *progress;
 
   memset (&hints, 0, sizeof (hints));
+#ifdef AI_ADDRCONFIG
   hints.ai_flags = AI_PASSIVE | AI_ADDRCONFIG;
+#else
+  hints.ai_flags = AI_PASSIVE;
+#endif
   hints.ai_socktype = SOCK_STREAM;
 
   port_s = g_strdup_printf ("%d", port);
