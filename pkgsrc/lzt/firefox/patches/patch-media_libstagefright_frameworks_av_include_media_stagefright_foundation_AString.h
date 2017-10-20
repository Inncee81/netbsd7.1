$NetBSD$

--- media/libstagefright/frameworks/av/include/media/stagefright/foundation/AString.h.orig	2016-05-12 17:13:16.000000000 +0000
+++ media/libstagefright/frameworks/av/include/media/stagefright/foundation/AString.h
@@ -18,6 +18,7 @@
 
 #define A_STRING_H_
 
+#include <cctype>
 #include <sys/types.h>
 
 namespace stagefright {
