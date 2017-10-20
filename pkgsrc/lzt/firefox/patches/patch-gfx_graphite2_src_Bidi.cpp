$NetBSD$

--- gfx/graphite2/src/Bidi.cpp.orig	2016-05-12 17:13:36.000000000 +0000
+++ gfx/graphite2/src/Bidi.cpp
@@ -31,6 +31,11 @@ of the License or (at your option) any l
 
 using namespace graphite2;
 
+#ifdef __sun
+#undef CS
+#undef ES
+#endif
+
 enum DirCode {  // Hungarian: dirc
         Unk        = -1,
         N          =  0,   // other neutrals (default) - ON
