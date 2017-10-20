$NetBSD$

--- defaults.c.orig	2000-03-02 21:44:29.000000000 +0000
+++ defaults.c
@@ -30,9 +30,7 @@
 #include <X11/Xutil.h>
 #include <X11/Xatom.h>
 #include <X11/Xresource.h>
-#ifdef OW_I18N_L4
 #include <sys/param.h>
-#endif
 
 #include "i18n.h"
 #include "ollocale.h"
@@ -89,6 +87,9 @@ GetUserDefaults(dpy)
 	    (void) strcat(filename, "/.Xdefaults-");
 #ifdef SVR4
 	    if (sysinfo(SI_HOSTNAME, hostname, sizeof(hostname)) != -1) {
+#endif
+#ifdef BSD
+	    if (0 == gethostname(hostname, sizeof(hostname))) {
 #else
 	    if (0 == gethostname(hostname, sizeof(hostname), &namelen)) {
 #endif
@@ -159,7 +160,7 @@ GetAppDefaults()
 	    return appDB;
     }
 
-    appDB = XrmGetFileDatabase("/usr/lib/X11/app-defaults/Olwm");
+    appDB = XrmGetFileDatabase(PREFIX "/lib/X11/app-defaults/Olwm");
     return appDB;
 }
 
