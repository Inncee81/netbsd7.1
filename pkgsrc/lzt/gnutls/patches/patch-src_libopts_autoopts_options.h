$NetBSD$

--- src/libopts/autoopts/options.h.orig	2015-11-25 18:23:34.000000000 +0000
+++ src/libopts/autoopts/options.h
@@ -62,7 +62,7 @@
 #    include <sysexits.h>
 #  endif /* HAVE_SYSEXITS_H */
 
-#  if defined(HAVE_STDBOOL_H)
+#  if defined(HAVE_STDBOOL_H) || defined(__APPLE__)
 #    include <stdbool.h>
 #  else
      typedef enum { false = 0, true = 1 } _Bool;
