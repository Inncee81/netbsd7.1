$NetBSD$

--- monitor/hal/ghaldrive.c.orig	2011-03-21 15:42:18.000000000 +0000
+++ monitor/hal/ghaldrive.c
@@ -377,7 +377,11 @@ g_hal_drive_new (GVolumeMonitor       *v
   drive = g_object_new (G_TYPE_HAL_DRIVE, NULL);
   drive->volume_monitor = volume_monitor;
   g_object_add_weak_pointer (G_OBJECT (volume_monitor), (gpointer) &(drive->volume_monitor));
+#ifdef __NetBSD__
+  drive->device_path = g_strdup (hal_device_get_property_string (device, "block.netbsd.raw_device"));
+#else
   drive->device_path = g_strdup (hal_device_get_property_string (device, "block.device"));
+#endif
   drive->device = g_object_ref (device);
   drive->pool = g_object_ref (pool);
 
