--- src/gpm-statistics.c.orig	2014-04-20 19:31:29.658178466 +0000
+++ src/gpm-statistics.c	2014-04-20 19:32:20.889177637 +0000
--- src/gpm-statistics.c.orig	2016-04-07 08:50:21.000000000 +0000
+++ src/gpm-statistics.c
@@ -1785,7 +1785,11 @@ main (int argc, char *argv[])
 	g_signal_connect (wakeups, "data-changed", G_CALLBACK (gpm_stats_data_changed_cb), NULL);
 #if !UP_CHECK_VERSION(0, 99, 0)
 	/* coldplug */
+#ifdef HAVE_OLD_UPOWER
 	ret = up_client_enumerate_devices_sync (client, NULL, NULL);
+#else
+        ret = FALSE;
+#endif	
 	if (!ret)
 		goto out;
 #endif
