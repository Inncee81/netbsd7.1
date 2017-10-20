$NetBSD$

--- lib-src/libnyquist/nyquist/cmt/cext.h.orig	2016-01-13 14:31:18.000000000 +0000
+++ lib-src/libnyquist/nyquist/cmt/cext.h
@@ -52,6 +52,8 @@ EXIT(n)  -- calls exit(n) after shutting
 
 #if HAS_SYS_TYPES_H
 #include <sys/types.h>
+#define ulong u_long
+#undef NEED_ULONG
 #endif
 
 #if HAS_MALLOC_H
