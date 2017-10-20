--- src/gpm-control.c.orig	2014-04-20 19:32:33.624174324 +0000
+++ src/gpm-control.c	2014-04-20 19:33:52.860168682 +0000
--- src/gpm-control.c.orig	2016-04-07 08:50:21.000000000 +0000
+++ src/gpm-control.c
@@ -295,7 +295,11 @@ gpm_control_suspend (GpmControl *control
 	}
 #if !UP_CHECK_VERSION(0, 99, 0)
 	else {
+#ifdef HAVE_OLD_UPOWER		
 		ret = up_client_suspend_sync (control->priv->client, NULL, error);
+#else
+                ret = FALSE;
+#endif
 	}
 #endif
 	egg_debug ("emitting resume");
@@ -408,7 +412,11 @@ gpm_control_hibernate (GpmControl *contr
 	}
 #if !UP_CHECK_VERSION(0, 99, 0)
 	else {
+#ifdef HAVE_OLD_UPOWER		
 		ret = up_client_hibernate_sync (control->priv->client, NULL, error);
+#else
+                ret = FALSE;
+#endif		
 	}
 #endif
 	egg_debug ("emitting resume");
