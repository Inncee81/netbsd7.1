$NetBSD$

--- plug-ins/twain/tw_mac.c.orig	2015-08-15 07:52:43.000000000 +0000
+++ plug-ins/twain/tw_mac.c
@@ -193,10 +193,12 @@ static void twainSetupMacUI()
   /* Voodoo magic fix inspired by java_swt launcher */
   /* Without this the icon setting doesn't work about half the time. */
 
+/*
   CGrafPtr p = BeginQDContextForApplicationDockTile();
   EndQDContextForApplicationDockTile(p);
 
   SetApplicationDockTileImage (icon);
+*/
 }
 
 int
