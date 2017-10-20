$NetBSD$

--- winpush.c.orig	1998-01-13 21:01:01.000000000 +0000
+++ winpush.c
@@ -95,11 +95,8 @@ WinPushPin	*winInfo;
 /* 
  * eventButtonRelease - handle button release events on the pushpin window 
  */
-static int
-eventButtonRelease(dpy, event, winInfo)
-Display	*dpy;
-XEvent	*event;
-WinPushPin	*winInfo;
+static void
+eventButtonRelease(Display *dpy, XEvent *event, WinPushPin *winInfo)
 {
 	FrameAllowEvents(winInfo->core.client, event->xbutton.time);
 	if (!AllButtonsUp(event))
@@ -121,11 +118,8 @@ WinPushPin	*winInfo;
 /* 
  * eventMotionNotify - handle pointer moves
  */
-static int
-eventMotionNotify(dpy, event, winInfo)
-Display	*dpy;
-XEvent	*event;
-WinPushPin	*winInfo;
+static void
+eventMotionNotify(Display *dpy, XEvent *event, WinPushPin *winInfo)
 {
 	Bool 	fInWindow;
 	Graphics_info	*gisNormal = WinGI(winInfo,NORMAL_GINFO);
