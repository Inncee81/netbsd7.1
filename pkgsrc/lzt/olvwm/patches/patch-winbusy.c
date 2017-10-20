$NetBSD$

--- winbusy.c.orig	1998-01-13 21:01:00.000000000 +0000
+++ winbusy.c
@@ -30,6 +30,8 @@
 #include "win.h"
 #include "globals.h"
 
+void PaintVirtualWindow(WinGenericFrame *win);
+
 /***************************************************************************
 * global data
 ***************************************************************************/
