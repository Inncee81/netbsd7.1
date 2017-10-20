$NetBSD$

--- daemon/gdmconsolekit.c.orig	2010-06-03 01:06:25.000000000 +0000
+++ daemon/gdmconsolekit.c
@@ -457,7 +457,11 @@ open_ck_session (struct passwd *pwent,
 		char *device;
 
 		/* FIXME: how does xorg construct this */
+#ifdef __NetBSD__
+		device = g_strdup_printf ("/dev/ttyE%d", d->vt - 1);
+#else
 		device = g_strdup_printf ("/dev/tty%d", d->vt);
+#endif
 		add_param_string (&iter_struct, "x11-display-device", device);
 		g_free (device);
 	}
