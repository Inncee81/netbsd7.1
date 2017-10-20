$NetBSD$

--- cursors.c.orig	1999-04-28 21:22:43.000000000 +0000
+++ cursors.c
@@ -278,7 +278,7 @@ initPointer(dpy, cmap, data, pointer)
 	    if (our_copy[0] == 'X')
 		font_file = "cursor";
 	    else if (our_copy[0] == 'O')
-		font_file = "-sun-open look cursor-----12-120-75-75-p-455-sunolcursor-1";
+		font_file = "olcursor";
 	    createCursor(dpy, cmap, pointer, cursor_id, font_file, end, ptr);
 	}
 	else {
