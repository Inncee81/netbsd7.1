$NetBSD$

--- daemon/gdmconfig.c.orig	2007-07-30 20:06:57.000000000 +0000
+++ daemon/gdmconfig.c
@@ -38,7 +38,7 @@
 #include <ctype.h>
 #include <fcntl.h>
 #include <sys/types.h>
-#include <sys/resource.h>
+#include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/resource.h>
 #include <signal.h>
@@ -1140,10 +1140,8 @@ _gdm_set_value_string (gchar *key, gchar
                      g_access (bin, X_OK) != 0) {
          gdm_info (_("%s: Standard X server not found; trying alternatives"),
                      "gdm_config_parse");
-         if (g_access ("/usr/X11R6/bin/X", X_OK) == 0) {
-            *setting = g_strdup ("/usr/X11R6/bin/X");
-         } else if (g_access ("/opt/X11R6/bin/X", X_OK) == 0) {
-            *setting = g_strdup ("/opt/X11R6/bin/X");
+         if (g_access ("/usr/X11R7/bin/X", X_OK) == 0) {
+            *setting = g_strdup ("/usr/X11R7/bin/X");
          } else if (g_access ("/usr/bin/X11/X", X_OK) == 0) {
             *setting = g_strdup ("/usr/bin/X11/X");
          } else
@@ -2068,12 +2066,12 @@ gdm_config_parse (void)
       bin = ve_first_word (GdmStandardXserver);
       if G_LIKELY (g_access (bin, X_OK) == 0) {
          server = GdmStandardXserver;
-      } else if (g_access ("/usr/bin/X11/X", X_OK) == 0) {
-         server = "/usr/bin/X11/X";
-      } else if (g_access ("/usr/X11R6/bin/X", X_OK) == 0) {
-         server = "/usr/X11R6/bin/X";
-      } else if (g_access ("/opt/X11R6/bin/X", X_OK) == 0) {
-         server = "/opt/X11R6/bin/X";
+      } else if (g_access ("/usr/pkg/bin/X", X_OK) == 0) {
+         server = "/usr/pkg/bin/X";
+      } else if (g_access ("/usr/X11R7/bin/X", X_OK) == 0) {
+         server = "/usr/X11R7/bin/X";
+      } else if (g_access ("/usr/pkg/X11R7/bin/X", X_OK) == 0) {
+         server = "/usr/pkg/X11R7/bin/X";
       }
       g_free (bin);
 
