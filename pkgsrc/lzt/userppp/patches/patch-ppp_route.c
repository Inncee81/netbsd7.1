$NetBSD$

--- ppp/route.c.orig	2016-12-11 15:02:40.444129904 +0000
+++ ppp/route.c
@@ -223,9 +223,6 @@ static struct bits {
   { RTF_DYNAMIC, 'D' },
   { RTF_MODIFIED, 'M' },
   { RTF_DONE, 'd' },
-  { RTF_CLONING, 'C' },
-  { RTF_XRESOLVE, 'X' },
-  { RTF_LLINFO, 'L' },
   { RTF_STATIC, 'S' },
   { RTF_PROTO1, '1' },
   { RTF_PROTO2, '2' },
