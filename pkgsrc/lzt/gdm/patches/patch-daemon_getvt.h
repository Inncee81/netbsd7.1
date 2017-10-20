$NetBSD$

--- daemon/getvt.h.orig	2010-06-03 01:06:25.000000000 +0000
+++ daemon/getvt.h
@@ -31,6 +31,10 @@
 #define GDM_USE_CONSIO_VT
 #endif
 
+#if defined(__NetBSD__)
+#define GDM_USE_WSCONS_VT
+#endif
+
 /* gets an argument we should pass to the X server, on
  * linux for example we get the first empty vt (higher than
  * or equal to GDM_KEY_FIRST_VT) and then return vt<number>
