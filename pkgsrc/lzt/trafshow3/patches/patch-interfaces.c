$NetBSD$

--- interfaces.c.orig	1998-08-22 08:19:03.000000000 +0000
+++ interfaces.c
@@ -14,6 +14,7 @@
 #include <config.h>
 #endif
 
+#include <string.h>
 #include <sys/param.h>
 #include <sys/types.h>
 #ifdef	HAVE_SYS_MBUF_H
@@ -24,6 +25,7 @@
 #include <netinet/ip.h>
 #ifdef	HAVE_NET_SLIP_H
 #include <net/slip.h>
+#define MLEN	128
 #include <net/slcompress.h>
 #endif
 
