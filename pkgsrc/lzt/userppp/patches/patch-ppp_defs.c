$NetBSD$

--- ppp/defs.c.orig	2000-10-28 23:56:03.000000000 +0000
+++ ppp/defs.c
@@ -28,6 +28,7 @@
 
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <netdb.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
