$NetBSD$

--- src/libopts/compat/compat.h.orig	2015-11-25 18:23:34.000000000 +0000
+++ src/libopts/compat/compat.h
@@ -182,7 +182,7 @@
 #  include <unistd.h>
 #endif
 
-#ifdef HAVE_STDBOOL_H
+#if defined(HAVE_STDBOOL_H) || defined(__APPLE__)
 #  include <stdbool.h>
 #else
    typedef enum { false = 0, true = 1 } _Bool;
