$NetBSD$

--- libseahorse/seahorse-util.c.orig	2010-08-28 16:44:35.000000000 +0000
+++ libseahorse/seahorse-util.c
@@ -39,6 +39,7 @@
 #endif 
 
 #include <sys/wait.h>
+#include <sys/types.h> /* XXX needed by some systems to define mode_t */
 #include <sys/stat.h>
 #include <unistd.h>
 #include <time.h>
