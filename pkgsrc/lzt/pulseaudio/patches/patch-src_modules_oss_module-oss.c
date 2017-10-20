$NetBSD$

--- src/modules/oss/module-oss.c.orig	2017-01-13 03:02:18.000000000 +0000
+++ src/modules/oss/module-oss.c
@@ -96,7 +96,11 @@ PA_MODULE_USAGE(
 PA_MODULE_DEPRECATED("Please use module-alsa-card instead of module-oss!");
 #endif
 
+#if defined(__NetBSD__)
+#define DEFAULT_DEVICE "/dev/audio"
+#else /* Linux */
 #define DEFAULT_DEVICE "/dev/dsp"
+#endif
 
 struct userdata {
     pa_core *core;
