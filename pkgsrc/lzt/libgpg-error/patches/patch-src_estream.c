$NetBSD$

--- src/estream.c.orig	2016-07-12 08:42:56.000000000 +0000
+++ src/estream.c
@@ -547,6 +547,7 @@ do_list_remove (estream_t stream, int wi
 /*
  * The atexit handler for this estream module.
  */
+__attribute__((destructor,used))
 static void
 do_deinit (void)
 {
@@ -578,7 +579,16 @@ _gpgrt_es_init (void)
   if (!initialized)
     {
       initialized = 1;
+#if 0
+      /* This library may be unloaded via dlclose() before
+       * exit() is called, causing the atexit handler to try
+       * to jump into unmapped address space, causing a segfault.
+       * This has been observed with apache and php.  Instead, use
+       * the destructor attribute, since that will cause it
+       * to be called on dlclose() as well.
+       */
       atexit (do_deinit);
+#endif
     }
   return 0;
 }
