$NetBSD$

--- ppp/id.c.orig	2016-12-12 01:10:13.380938927 +0000
+++ ppp/id.c
@@ -52,6 +52,7 @@
 #else
 #include <libutil.h>
 #endif
+#include <util.h>
 #include <utmp.h>
 
 #include <util.h>
