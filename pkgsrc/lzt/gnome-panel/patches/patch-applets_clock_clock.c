$NetBSD$

--- applets/clock/clock.c.orig	2010-06-22 23:00:27.000000000 +0000
+++ applets/clock/clock.c
@@ -70,6 +70,10 @@
 #include "set-timezone.h"
 #include "system-timezone.h"
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define daylight 1
+#endif
+
 #define INTERNETSECOND (864)
 #define INTERNETBEAT   (86400)
 
