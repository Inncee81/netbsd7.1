$NetBSD$

--- media/libsoundtouch/src/cpu_detect_x86.cpp.orig	2016-05-12 17:13:16.000000000 +0000
+++ media/libsoundtouch/src/cpu_detect_x86.cpp
@@ -125,7 +125,9 @@ uint detectCPUextensions(void)
 #endif
 
     return res & ~_dwDisabledISA;
-
+#elif defined(__GNUC__)
+    // No cpuid.h --> no cpuid support
+    return 0;
 #else
 
 /// One of these is true:
