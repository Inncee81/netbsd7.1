$NetBSD$

--- mozglue/build/arm.h.orig	2016-09-05 20:12:58.000000000 +0000
+++ mozglue/build/arm.h
@@ -76,7 +76,7 @@
 #  endif
 
   // Currently we only have CPU detection for Linux via /proc/cpuinfo
-#  if defined(__linux__) || defined(ANDROID)
+#  if defined(__linux__) || defined(ANDROID) || defined(__NetBSD__)
 #    define MOZILLA_ARM_HAVE_CPUID_DETECTION 1
 #  endif
 
