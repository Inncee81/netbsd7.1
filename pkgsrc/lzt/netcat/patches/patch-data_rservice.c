$NetBSD$

--- data/rservice.c.orig	1996-01-31 18:45:08.000000000 +0000
+++ data/rservice.c
@@ -10,6 +10,7 @@
    ... whatever.  _H*/
 
 #include <stdio.h>
+#include <string.h>
 
 /* change if you like; "id" is a good one for figuring out if you won too */
 static char cmd[] = "pwd";
