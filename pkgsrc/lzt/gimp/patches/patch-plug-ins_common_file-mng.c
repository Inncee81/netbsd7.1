$NetBSD$

--- plug-ins/common/file-mng.c.orig	2015-08-20 22:57:28.000000000 +0000
+++ plug-ins/common/file-mng.c
@@ -56,7 +56,6 @@
 /* libpng and jpeglib are currently used in this plug-in. */
 
 #include <png.h>
-#include <jpeglib.h>
 
 
 /* Grrr. The grrr is because the following have to be defined
@@ -86,6 +85,7 @@
 
 #include <libmng.h>
 
+#include <jpeglib.h>
 #include "libgimp/gimp.h"
 #include "libgimp/gimpui.h"
 
