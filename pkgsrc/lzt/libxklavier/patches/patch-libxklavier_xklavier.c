$NetBSD$

--- libxklavier/xklavier.c.orig	2013-02-20 01:10:50.000000000 +0000
+++ libxklavier/xklavier.c
@@ -18,6 +18,7 @@
  */
 
 #include <string.h>
+#include <stdlib.h>
 #include <time.h>
 
 #include <X11/Xatom.h>
@@ -517,8 +518,7 @@ xkl_engine_ensure_vtable_inited(XklEngin
 	if (xkl_engine_priv(engine, backend_id) == NULL) {
 		xkl_debug(0, "ERROR: XKL VTable is NOT initialized.\n");
 		/* force the crash! */
-		p = NULL;
-		*p = '\0';
+		abort();
 	}
 }
 
