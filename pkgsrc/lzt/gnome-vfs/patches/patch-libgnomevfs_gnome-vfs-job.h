$NetBSD$

--- libgnomevfs/gnome-vfs-job.h.orig	2010-02-09 12:16:14.000000000 +0000
+++ libgnomevfs/gnome-vfs-job.h
@@ -56,7 +56,7 @@ G_STMT_START{					\
 	gettimeofday(&_tt, NULL);		\
 	printf ("%ld:%6.ld ", _tt.tv_sec, _tt.tv_usec); \
 	g_static_mutex_lock (&debug_mutex);	\
-	fputs (__FUNCTION__, stdout);		\
+	fputs (G_GNUC_FUNCTION, stdout);	\
 	printf (": %d ", __LINE__);		\
 	printf x;				\
 	fputc ('\n', stdout);			\
