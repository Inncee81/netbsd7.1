$NetBSD$

--- libgnomevfs/gnome-vfs-unix-mounts.c.orig	2010-02-09 12:16:14.000000000 +0000
+++ libgnomevfs/gnome-vfs-unix-mounts.c
@@ -475,7 +475,11 @@ get_mtab_monitor_file (void)
 gboolean
 _gnome_vfs_get_current_unix_mounts (GList **return_list)
 {
+#if defined(HAVE_STATVFS) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
+    	struct statvfs *mntent = NULL;
+#else
     	struct statfs *mntent = NULL;
+#endif
 	int num_mounts, i;
 	GnomeVFSUnixMount *mount_entry;
 
@@ -492,7 +496,11 @@ _gnome_vfs_get_current_unix_mounts (GLis
 		mount_entry->mount_path = g_strdup (mntent[i].f_mntonname);
 		mount_entry->device_path = g_strdup (mntent[i].f_mntfromname);
 		mount_entry->filesystem_type = g_strdup (mntent[i].f_fstypename);
+#if defined(HAVE_STATVFS) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
+		if (mntent[i].f_flag & MNT_RDONLY) {
+#else
 		if (mntent[i].f_flags & MNT_RDONLY) {
+#endif
 		    	mount_entry->is_read_only = TRUE;
 		}
 
