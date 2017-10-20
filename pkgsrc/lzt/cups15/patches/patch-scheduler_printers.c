$NetBSD$

--- scheduler/printers.c.orig	2012-02-15 23:21:06.000000000 +0000
+++ scheduler/printers.c
@@ -80,6 +80,9 @@
 #  include <asl.h>
 #endif /* __APPLE__ */
 
+#if defined(HAVE_STATVFS) && ( defined(__NetBSD__) || defined(__sun) )
+#undef HAVE_STATFS
+#endif
 
 /*
  * Local functions...
