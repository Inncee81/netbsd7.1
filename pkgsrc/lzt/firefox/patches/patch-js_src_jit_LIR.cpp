$NetBSD$

--- js/src/jit/LIR.cpp.orig	2016-10-31 20:15:35.000000000 +0000
+++ js/src/jit/LIR.cpp
@@ -331,7 +331,7 @@ LNode::printName(GenericPrinter& out, Op
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        out.printf("%c", tolower(name[i]));
+        out.printf("%c", tolower((unsigned char)name[i]));
 }
 
 void
