$NetBSD$

--- gif.c.orig	2000-03-02 21:44:42.000000000 +0000
+++ gif.c
@@ -56,7 +56,10 @@ struct {
 	int     disposal;
 } Gif89 = { -1, -1, -1, 0 };
 
-extern XImage* ReadImage();
+static XImage* ReadImage();
+static int ReadColorMap();
+static int DoExtension();
+static int GetDataBlock();
 
 XImage *ReadGIF(dpy, fd, pNcolors, pColors)
 Display *dpy;
