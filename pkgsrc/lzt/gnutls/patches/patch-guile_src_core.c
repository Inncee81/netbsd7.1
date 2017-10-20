$NetBSD$

--- guile/src/core.c.orig	2015-01-19 17:38:09.000000000 +0000
+++ guile/src/core.c
@@ -28,7 +28,7 @@
 #include <gnutls/openpgp.h>
 #include <libguile.h>
 
-#include <alloca.h>
+#include <stdlib.h>
 
 #include "enums.h"
 #include "smobs.h"
