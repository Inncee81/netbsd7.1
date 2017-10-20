$NetBSD$

--- ipc/chromium/src/build/build_config.h.orig	2016-09-05 20:12:53.000000000 +0000
+++ ipc/chromium/src/build/build_config.h
@@ -32,6 +32,8 @@
 #define OS_NETBSD 1
 #elif defined(__OpenBSD__)
 #define OS_OPENBSD 1
+#elif defined(__sun)
+#define OS_SOLARIS 1
 #elif defined(_WIN32)
 #define OS_WIN 1
 #else
@@ -47,7 +49,7 @@
 
 // For access to standard POSIX features, use OS_POSIX instead of a more
 // specific macro.
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD) || defined(OS_SOLARIS)
 #define OS_POSIX 1
 #endif
 
