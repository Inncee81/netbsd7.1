$NetBSD$

--- modules/sftp-method.c.orig	2010-02-09 12:16:14.000000000 +0000
+++ modules/sftp-method.c
@@ -3144,11 +3144,12 @@ do_rename (GnomeVFSMethod  *method,
 	buffer_send (&msg, conn->out_fd);
 	buffer_free (&msg);
 
+	res = iobuf_read_result (conn->in_fd, id);
+
+ bail:
 	g_free (old_path);
 	g_free (new_path);
 
-	res = iobuf_read_result (conn->in_fd, id);
-
 	sftp_connection_unref (conn);
 	sftp_connection_unlock (conn);
 
