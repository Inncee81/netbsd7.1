$NetBSD$

--- olwmslave/cmdstream.c.orig	1993-06-29 05:12:10.000000000 +0000
+++ olwmslave/cmdstream.c
@@ -50,10 +50,10 @@ static	CmdInfo		cmdInfo = {
  *      Local Forward Declarations
  * ---------------------------------------------------------------------*/
 
-Command		*MatchCommand();
-CmdAttr		*MatchAttr();
-int		EncodeAttrValue();
-int		DecodeAttrValue();
+static Command		*MatchCommand();
+static CmdAttr		*MatchAttr();
+static int		EncodeAttrValue();
+static int		DecodeAttrValue();
 
 /* ----------------------------------------------------------------------
  *      SetCmdStream
