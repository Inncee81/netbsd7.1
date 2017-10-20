$NetBSD$

--- src/oss.c.orig	2014-10-06 02:02:30.000000000 +0000
+++ src/oss.c
@@ -369,7 +369,7 @@ static size_t osswrite(
         size_t cbStride;
         int cbWritten;
 
-        cStride = cInput;
+        cStride = cInputRemaining;
         if (cStride > pPriv->cOutput) {
             cStride = pPriv->cOutput;
         }
