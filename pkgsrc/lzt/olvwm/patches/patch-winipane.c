$NetBSD$

--- winipane.c.orig	1998-01-13 21:01:01.000000000 +0000
+++ winipane.c
@@ -72,10 +72,8 @@ static ClassPane classIconPane;
  * drawIPane -- draw the pane window
  */
 /*ARGSUSED*/	/* dpy arg will be used when multiple Displays supported */
-static int
-drawIPane(dpy, winInfo)
-Display	*dpy;
-WinIconPane *winInfo;
+static void
+drawIPane(Display *dpy, WinIconPane *winInfo)
 {
     Window 	pane = winInfo->core.self;
     GC 		gc;
