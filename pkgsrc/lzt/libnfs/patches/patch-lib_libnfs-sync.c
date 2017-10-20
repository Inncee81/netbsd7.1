$NetBSD$

--- lib/libnfs-sync.c.orig	2017-06-16 19:48:10.000000000 +0000
+++ lib/libnfs-sync.c
@@ -21,6 +21,8 @@
 #include "config.h"
 #endif
 
+#include <sys/types.h>
+
 #ifdef AROS
 #include "aros_compat.h"
 #endif
