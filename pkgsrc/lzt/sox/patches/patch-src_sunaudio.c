$NetBSD$

--- src/sunaudio.c.orig	2014-10-06 01:59:34.000000000 +0000
+++ src/sunaudio.c
@@ -443,7 +443,7 @@ static size_t sunwrite(
         size_t cbStride;
         int cbWritten;
 
-        cStride = cInput;
+        cStride = cInputRemaining;
         if (cStride > pPriv->cOutput) {
             cStride = pPriv->cOutput;
         }
