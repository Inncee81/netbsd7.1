$NetBSD$

--- src/effects/NoiseRemoval.cpp.orig	2016-01-13 14:31:24.000000000 +0000
+++ src/effects/NoiseRemoval.cpp
@@ -53,6 +53,10 @@
 
 #include <math.h>
 
+#ifdef __sun
+#include <ieeefp.h>
+#endif
+
 #if defined(__WXMSW__) && !defined(__CYGWIN__)
 #include <float.h>
 #define finite(x) _finite(x)
