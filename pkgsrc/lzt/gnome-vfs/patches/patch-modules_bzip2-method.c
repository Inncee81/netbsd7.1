$NetBSD$

--- modules/bzip2-method.c.orig	2010-02-09 12:16:14.000000000 +0000
+++ modules/bzip2-method.c
@@ -36,7 +36,7 @@
 
 #include <bzlib.h>
 
-#ifdef HAVE_OLDER_BZIP2
+#if defined(HAVE_OLDER_BZIP2) && !defined(__APPLE__)
 #define BZ2_bzDecompressInit  bzDecompressInit
 #define BZ2_bzCompressInit    bzCompressInit
 #define BZ2_bzDecompress      bzDecompress
