$NetBSD$

--- daemon/gdm-daemon-config.c.orig	2010-06-03 01:06:25.000000000 +0000
+++ daemon/gdm-daemon-config.c
@@ -40,7 +40,7 @@
 #include <fcntl.h>
 #include <string.h>
 #include <sys/types.h>
-#include <sys/resource.h>
+#include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/resource.h>
 #include <signal.h>
