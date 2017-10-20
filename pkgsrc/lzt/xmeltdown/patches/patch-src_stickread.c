$NetBSD$

--- src/stickread.c.orig	2016-11-29 20:47:53.000000000 +0000
+++ src/stickread.c
@@ -85,8 +85,8 @@ int main(int argc, char** argv)
 }
 void HandleKeyPress(XKeyEvent* pevent)
 {
-	if (pevent->keycode == 'q') ;
-	exit(0);
+	if (pevent->keycode == 'q')
+		exit(0);
 }
 
 void Interpolate(Skeleton** skellist, int steps)
