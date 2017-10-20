$NetBSD$

--- modules/file-method-acl.c.orig	2010-02-09 12:16:14.000000000 +0000
+++ modules/file-method-acl.c
@@ -35,6 +35,9 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #ifdef HAVE_SYS_RESOURCE_H
+#ifdef HAVE_SYS_TIME_H
+#include <sys/time.h>	/* <sys/resource.h> needs this on MacOS X */
+#endif
 #include <sys/resource.h>
 #endif
 
