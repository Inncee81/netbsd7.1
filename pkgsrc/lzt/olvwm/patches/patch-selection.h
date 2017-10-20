$NetBSD$

--- selection.h.orig	1998-01-13 21:01:04.000000000 +0000
+++ selection.h
@@ -17,7 +17,6 @@
 extern	Time	SelectionTime;
 
 extern	Bool	IsSelected(/*  client  */);
-extern	int	AddSelection(/*  client, time  */);
 extern	Bool	RemoveSelection(/*  client  */);
 extern	Bool	ToggleSelection(/*  client, time  */);
 extern	void	ClearSelections(/*  dpy  */);
