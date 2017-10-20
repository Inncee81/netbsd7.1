$NetBSD$

--- image/decoders/nsIconDecoder.cpp.orig	2016-10-31 20:15:32.000000000 +0000
+++ image/decoders/nsIconDecoder.cpp
@@ -97,7 +97,8 @@ nsIconDecoder::ReadRowOfPixels(const cha
       return AsVariant(WriteState::NEED_MORE_DATA);  // Done with this row.
     }
 
-    uint32_t pixel = *reinterpret_cast<const uint32_t*>(aData);
+    uint32_t pixel;
+    memcpy(&pixel, aData, 4);
     aData += 4;
     aLength -= 4;
 
