$NetBSD$

--- data/data.c.orig	1996-02-27 13:43:48.000000000 +0000
+++ data/data.c
@@ -16,6 +16,7 @@
    *Hobbit*, started 951004 or so and randomly screwed around with since */
 
 #include <stdio.h>
+#include <string.h>
 
 #ifdef MSDOS				/* for MSC only at the moment... */
 #include <fcntl.h>
