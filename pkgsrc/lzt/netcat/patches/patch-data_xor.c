$NetBSD$

--- data/xor.c.orig	1996-02-18 03:18:16.000000000 +0000
+++ data/xor.c
@@ -14,6 +14,7 @@
    *Hobbit*, 960208 */
 
 #include <stdio.h>
+#include <string.h>
 #include <fcntl.h>
 
 char buf[8192];
