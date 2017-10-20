$NetBSD$

--- daemon/gvfsbackendtest.c.orig	2011-03-21 15:42:18.000000000 +0000
+++ daemon/gvfsbackendtest.c
@@ -92,7 +92,7 @@ open_idle_cb (gpointer data)
       return FALSE;
     }
   
-  fd = g_open (job->filename, O_RDONLY);
+  fd = g_open (job->filename, O_RDONLY, 0);
   if (fd == -1)
     {
       int errsv = errno;
