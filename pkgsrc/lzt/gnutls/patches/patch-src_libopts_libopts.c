$NetBSD$

--- src/libopts/libopts.c.orig	2015-11-25 18:23:34.000000000 +0000
+++ src/libopts/libopts.c
@@ -1,3 +1,7 @@
+#include <config.h>
+#if ENABLE_NLS
+#include <gettext.h>
+#endif
 #define  AUTOOPTS_INTERNAL 1
 #include "autoopts/project.h"
 #define  LOCAL static
