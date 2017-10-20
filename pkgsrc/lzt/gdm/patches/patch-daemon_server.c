$NetBSD$

--- daemon/server.c.orig	2010-06-03 01:06:25.000000000 +0000
+++ daemon/server.c
@@ -30,6 +30,7 @@
 #include <pwd.h>
 #include <grp.h>
 #include <sys/types.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
