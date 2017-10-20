$NetBSD$

--- applets/clock/clock-location.c.orig	2010-02-09 12:32:08.000000000 +0000
+++ applets/clock/clock-location.c
@@ -27,6 +27,10 @@
 #include "set-timezone.h"
 #include "system-timezone.h"
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#define daylight 1
+#endif
+
 G_DEFINE_TYPE (ClockLocation, clock_location, G_TYPE_OBJECT)
 
 typedef struct {
