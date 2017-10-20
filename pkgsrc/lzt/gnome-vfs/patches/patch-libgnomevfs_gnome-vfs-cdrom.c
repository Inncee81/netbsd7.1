$NetBSD$

--- libgnomevfs/gnome-vfs-cdrom.c.orig	2010-02-09 12:16:14.000000000 +0000
+++ libgnomevfs/gnome-vfs-cdrom.c
@@ -37,6 +37,8 @@
 
 #ifdef __linux__
 #include <linux/cdrom.h>
+#elif defined(__APPLE__)
+#include <modules/cdda-cdrom-extensions.h>
 #endif
 
 #ifdef HAVE_SYS_CDIO_H
