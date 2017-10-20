$NetBSD$

--- client/gvfsfusedaemon.c.orig	2011-03-21 15:42:18.000000000 +0000
+++ client/gvfsfusedaemon.c
@@ -26,7 +26,9 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#if !defined(__NetBSD__)
 #include <sys/vfs.h>
+#endif
 #include <sys/time.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -41,8 +43,6 @@
 #include <glib/gprintf.h>
 #include <gio/gio.h>
 
-#include <glib/gurifuncs.h>
-
 /* stuff from common/ */
 #include <gdaemonmount.h>
 #include <gvfsdaemonprotocol.h>
@@ -2340,7 +2340,9 @@ vfs_init (struct fuse_conn_info *conn)
   subthread = g_thread_create ((GThreadFunc) subthread_main, NULL, FALSE, NULL);
 
   /* Indicate O_TRUNC support for open() */
+#ifdef FUSE_CAP_ATOMIC_O_TRUNC
   conn->want |= FUSE_CAP_ATOMIC_O_TRUNC;
+#endif
 
   return NULL;
 }
