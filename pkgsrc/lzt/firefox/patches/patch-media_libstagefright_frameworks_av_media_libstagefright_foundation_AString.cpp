$NetBSD$

--- media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp.orig	2016-05-12 17:13:17.000000000 +0000
+++ media/libstagefright/frameworks/av/media/libstagefright/foundation/AString.cpp
@@ -23,6 +23,10 @@
 #include "ADebug.h"
 #include "AString.h"
 
+#if defined(__NetBSD__) && defined(tolower)
+#undef tolower
+#endif
+
 namespace stagefright {
 
 // static
