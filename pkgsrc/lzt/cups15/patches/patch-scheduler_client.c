$NetBSD$

--- scheduler/client.c.orig	2012-03-07 06:05:39.000000000 +0000
+++ scheduler/client.c
@@ -4075,6 +4075,14 @@ is_path_absolute(const char *path)	/* I 
     return (0);
 
  /*
+  * Check for "<" or quotes in the path and reject since this is probably
+  * someone trying to inject HTML...
+  */
+
+  if (strchr(path, '<') != NULL || strchr(path, '\"') != NULL || strchr(path, '\'') != NULL)
+    return (0);
+
+ /*
   * Check for "/.." in the path...
   */
 
