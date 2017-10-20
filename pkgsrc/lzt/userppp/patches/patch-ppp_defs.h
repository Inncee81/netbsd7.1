$NetBSD$

--- ppp/defs.h.orig	2000-10-30 00:15:04.000000000 +0000
+++ ppp/defs.h
@@ -32,8 +32,6 @@
 #endif
 #define NMODEMS		2
 
-#define _PATH_PPP	"/etc/ppp"
-
 #define TUN_NAME	"tun"
 #define TUN_PREFIX	(_PATH_DEV TUN_NAME)	/* /dev/tun */
 
