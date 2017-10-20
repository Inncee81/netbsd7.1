$NetBSD$

--- battstat/power-management.c.orig	2016-01-03 01:03:50.000000000 +0000
+++ battstat/power-management.c
@@ -241,6 +241,7 @@ apm_readinfo (BatteryStatus *status)
 #include <sys/param.h>
 #if defined(__NetBSD__)
 #include <dev/apm/apmio.h>
+#include <string.h>
 #else /* __OpenBSD__ */
 #include <machine/apmvar.h>
 #endif
@@ -253,6 +254,12 @@ apm_readinfo (BatteryStatus *status)
   /* Code for OpenBSD by Joe Ammond <jra@twinight.org>. Using the same
      procedure as for FreeBSD.
   */
+
+  /*
+  CANNOT TRUST on ACPI... so rely on battery life and minutes only
+  Nervoso@k1.com.br
+  */
+
 #if defined(__NetBSD__)
   struct apm_power_info apminfo;
 #else /* __OpenBSD__ */
@@ -266,22 +273,32 @@ apm_readinfo (BatteryStatus *status)
   if (DEBUG) g_print("apm_readinfo() (OpenBSD)\n");
 #endif
 
-  fd = open(APMDEVICE, O_RDONLY);
-  if (fd == -1)
-  {
-    pm_initialised = 0;
-    return ERR_OPEN_APMDEV;
+  status->present = FALSE;
+  if ((fd = open(APMDEVICE, O_RDONLY)) < 0) 
+    	return ERR_OPEN_APMDEV;
+  bzero(&apminfo,sizeof(apminfo));
+  if (ioctl(fd, APM_IOC_GETPOWER, &apminfo)< 0) {
+    close(fd);
+    return "error ioctl(APM_IOC_GETPOWER)";
   }
-  if (ioctl(fd, APM_IOC_GETPOWER, &apminfo) == -1)
-    err(1, "ioctl(APM_IOC_GETPOWER)");
   close(fd);
-
+  if (apminfo.battery_life == 255) {	/* NOOOOO BATTERY */
+  	status->on_ac_power = TRUE;
+  	status->percent = 0;
+  	status->charging = 0;
+  	status->minutes = 0;
+	return NULL;
+  }
   status->present = TRUE;
-  status->on_ac_power = apminfo.ac_state ? 1 : 0;
-  status->percent = apminfo.battery_life;
-  status->charging = (apminfo.battery_state == 3) ? TRUE : FALSE;
-  status->minutes = apminfo.minutes_left;
-
+  status->percent=apminfo.battery_life;
+  status-> charging=FALSE;
+  if (apminfo.minutes_left == 0) {	/* HAS BATTERY and charging */
+	status-> on_ac_power=TRUE;
+  	status-> charging=TRUE;
+	return NULL;
+  }
+  status-> minutes=apminfo.minutes_left;
+  status-> on_ac_power=FALSE;		/* on BATTERY */
   return NULL;
 }
 
