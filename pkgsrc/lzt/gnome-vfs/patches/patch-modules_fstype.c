$NetBSD$

--- modules/fstype.c.orig	2010-02-09 12:16:14.000000000 +0000
+++ modules/fstype.c
@@ -347,8 +347,12 @@ filesystem_type_uncached (char *path, ch
 	fstype_internal_error (1, errno, "%s", path);
     }
   else
+#if defined(__NetBSD__)
+    type = fss.f_fstypename;
+#else
     type = fss.f_basetype;
 #endif
+#endif
 
 #ifdef FSTYPE_STATFS		/* 4.4BSD.  */
   struct statfs fss;
