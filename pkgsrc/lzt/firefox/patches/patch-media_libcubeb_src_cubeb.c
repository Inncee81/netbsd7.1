$NetBSD$

--- media/libcubeb/src/cubeb.c.orig	2016-10-31 20:15:39.000000000 +0000
+++ media/libcubeb/src/cubeb.c
@@ -60,6 +60,9 @@ int audiotrack_init(cubeb ** context, ch
 #if defined(USE_KAI)
 int kai_init(cubeb ** context, char const * context_name);
 #endif
+#if defined(USE_OSS)
+int oss_init(cubeb ** context, char const * context_name);
+#endif
 
 
 int
@@ -153,6 +156,9 @@ cubeb_init(cubeb ** context, char const 
 #if defined(USE_KAI)
     kai_init,
 #endif
+#if defined(USE_OSS)
+    oss_init,
+#endif
   };
   int i;
 
