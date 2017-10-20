$NetBSD$

--- cipher/rijndael-arm.S.orig	2016-07-14 09:19:17.000000000 +0000
+++ cipher/rijndael-arm.S
@@ -19,6 +19,7 @@
  */
 
 #include <config.h>
+#undef __ARM_FEATURE_UNALIGNED
 
 #if defined(__ARMEL__)
 #ifdef HAVE_COMPATIBLE_GCC_ARM_PLATFORM_AS
