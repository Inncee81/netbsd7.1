$NetBSD$

--- libgnomevfs/xdgmime.c.orig	2010-02-09 12:16:14.000000000 +0000
+++ libgnomevfs/xdgmime.c
@@ -254,7 +254,7 @@ xdg_run_command_on_dirs (XdgDirectoryFun
 
   xdg_data_dirs = getenv ("XDG_DATA_DIRS");
   if (xdg_data_dirs == NULL)
-    xdg_data_dirs = "/usr/local/share/:/usr/share/";
+    xdg_data_dirs = PREFIX "/share/";
 
   ptr = xdg_data_dirs;
 
