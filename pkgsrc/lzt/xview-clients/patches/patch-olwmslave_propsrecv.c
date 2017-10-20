$NetBSD$

--- olwmslave/propsrecv.c.orig	1993-06-29 05:12:13.000000000 +0000
+++ olwmslave/propsrecv.c
@@ -15,7 +15,7 @@ static char     sccsid[] = "@(#) propsre
 #include "propscmd.h"
 
 extern	int	ShowWindowProps();
-	void	ReceivePropsCmd();
+static	void	ReceivePropsCmd();
 
 /* ----------------------------------------------------------------------
  *	RegisterPropsWindow
