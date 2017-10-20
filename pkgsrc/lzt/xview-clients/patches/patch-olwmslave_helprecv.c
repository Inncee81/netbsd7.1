$NetBSD$

--- olwmslave/helprecv.c.orig	1993-06-29 05:12:11.000000000 +0000
+++ olwmslave/helprecv.c
@@ -15,7 +15,7 @@ static	char	sccsid[] = "@(#) helprecv.c 
 #include "helpcmd.h"
 
 extern	int	ShowHelpWindow();
-	void	ReceiveHelpCmd();
+static	void	ReceiveHelpCmd();
 
 /* ----------------------------------------------------------------------
  *	RegisterHelpWindow
