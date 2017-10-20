$NetBSD$

--- libgnomevfs/gnome-vfs-utils.c.orig	2010-02-09 12:16:14.000000000 +0000
+++ libgnomevfs/gnome-vfs-utils.c
@@ -49,6 +49,12 @@
 #include <sys/param.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+
+#ifdef __APPLE__
+#include <sys/mount.h>
+#define HAVE_STATVFS 0
+#endif
+
 #include <unistd.h>
 
 #define KILOBYTE_FACTOR 1024.0
