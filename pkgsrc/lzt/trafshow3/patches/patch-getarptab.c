$NetBSD$

--- getarptab.c.orig	2016-12-06 05:11:29.060314990 +0000
+++ getarptab.c
@@ -13,11 +13,11 @@
 #ifdef	HAVE_CONFIG_H
 #include <config.h>
 #endif
+#include <sys/types.h>
 
 #ifdef	HAVE_RTF_LLINFO		/* BSD systems */
 
 #include <sys/param.h>
-#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/sysctl.h>
 
