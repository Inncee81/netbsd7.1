$NetBSD$

--- lib-src/libnyquist/nyquist/nyqsrc/sndread.c.orig	2016-01-13 14:31:18.000000000 +0000
+++ lib-src/libnyquist/nyquist/nyqsrc/sndread.c
@@ -167,7 +167,7 @@ LVAL snd_make_read(
 #ifdef XL_BIG_ENDIAN
         long format = SF_ENDIAN_LITTLE;
 #endif
-        susp->sf_info.format |= format;
+        susp->sf_info.format |= (int) format;
     }
 
     susp->sndfile = NULL;
