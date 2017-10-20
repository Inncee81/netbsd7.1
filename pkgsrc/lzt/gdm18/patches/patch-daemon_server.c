$NetBSD$

--- daemon/server.c.orig	2007-07-30 20:06:56.000000000 +0000
+++ daemon/server.c
@@ -28,6 +28,7 @@
 #include <pwd.h>
 #include <grp.h>
 #include <sys/types.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
