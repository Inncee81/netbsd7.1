$NetBSD$

--- monitor/hal/ghalvolumemonitor.c.orig	2011-03-21 15:42:18.000000000 +0000
+++ monitor/hal/ghalvolumemonitor.c
@@ -1323,7 +1323,11 @@ update_discs (GHalVolumeMonitor *monitor
               GFile *foreign_mount_root;
 
               /* the gvfsd-cdda backend uses URI's like these */
+#ifdef __NetBSD__
+	      device_basename = g_path_get_basename (hal_device_get_property_string (d, "block.netbsd.raw_device"));
+#else
               device_basename = g_path_get_basename (hal_device_get_property_string (d, "block.device"));
+#endif
               uri = g_strdup_printf ("cdda://%s", device_basename);
               foreign_mount_root = g_file_new_for_uri (uri);
               g_free (device_basename);
