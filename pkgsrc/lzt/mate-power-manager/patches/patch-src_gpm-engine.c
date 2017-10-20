--- src/gpm-engine.c.orig	2014-04-20 19:34:27.136166463 +0000
+++ src/gpm-engine.c	2014-04-20 19:35:40.970161631 +0000
--- src/gpm-engine.c.orig	2016-04-07 08:50:21.000000000 +0000
+++ src/gpm-engine.c
@@ -837,7 +837,11 @@ gpm_engine_coldplug_idle_cb (GpmEngine *
 	g_return_val_if_fail (GPM_IS_ENGINE (engine), FALSE);
 #if !UP_CHECK_VERSION(0, 99, 0)
 	/* get devices from UPower */
+#ifdef HAVE_OLD_UPOWER	
 	ret = up_client_enumerate_devices_sync (engine->priv->client, NULL, &error);
+#else
+        ret = FALSE;
+#endif	
 	if (!ret) {
 		egg_error ("failed to get device list: %s", error->message);
 		g_error_free (error);
