$NetBSD$

--- winicon.c.orig	2000-03-02 21:42:07.000000000 +0000
+++ winicon.c
@@ -52,6 +52,10 @@ static ClassIconFrame classIconFrame;
 * forward-declared functions
 ***************************************************************************/
 
+static int	heightTopIcon();
+static int	heightBottomIcon();
+static int	widthBothIcon();
+
 /***************************************************************************
 * private event functions
 ***************************************************************************/
