$NetBSD$

--- winpane.c.orig	1998-01-13 21:01:01.000000000 +0000
+++ winpane.c
@@ -156,12 +156,9 @@ WinPane	*winInfo;
 /*
  * eventExtension - handle extension events
  */
-static int
+static void
 /* ARGSUSED */
-eventExtension(dpy, event, winInfo)
-    Display	*dpy;
-    XEvent	*event;
-    WinPane	*winInfo;
+eventExtension(Display *dpy, XEvent *event, WinPane *winInfo)
 {
 #ifdef SHAPE
     XShapeEvent *se;
