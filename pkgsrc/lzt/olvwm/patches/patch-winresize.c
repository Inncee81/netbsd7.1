$NetBSD$

--- winresize.c.orig	1998-01-13 21:01:02.000000000 +0000
+++ winresize.c
@@ -70,11 +70,8 @@ resizeCallback(dpy, winInfo)
 /* 
  * eventButtonPress - handle button press events on the resize window 
  */
-static int
-eventButtonPress(dpy, event, winInfo)
-Display	*dpy;
-XEvent	*event;
-WinResize	*winInfo;
+static void
+eventButtonPress(Display *dpy, XEvent *event, WinResize *winInfo)
 {
 	unsigned int ignoremask =
 	    ModMaskMap[MOD_CONSTRAIN] | ModMaskMap[MOD_INVERT];
