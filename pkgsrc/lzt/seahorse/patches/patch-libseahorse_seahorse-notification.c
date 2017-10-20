$NetBSD$

--- libseahorse/seahorse-notification.c.orig	2009-04-18 03:22:13.000000000 +0000
+++ libseahorse/seahorse-notification.c
@@ -37,8 +37,14 @@
 
 #ifdef HAVE_LIBNOTIFY
 #include <libnotify/notify.h>
+
+#ifndef NOTIFY_CHECK_VERSION
+#define NOTIFY_CHECK_VERSION(x,y,z) 0
+#endif
+
 #endif
 
+
 /* -----------------------------------------------------------------------------
  * SEAHORSE NOTIFICATION 
  */
@@ -231,7 +237,12 @@ setup_libnotify_notification (SeahorseNo
     heading = format_key_text (snotif->heading);
     message = format_key_text (snotif->message);
     
+/* libnotify 0.7.0 and later has no support for attaching to widgets */
+#if NOTIFY_CHECK_VERSION(0,7,0)
+    notif = notify_notification_new (heading, message, snotif->icon);
+#else
     notif = notify_notification_new (heading, message, snotif->icon, attachto);
+#endif
     
     g_free (heading);
     g_free (message);
