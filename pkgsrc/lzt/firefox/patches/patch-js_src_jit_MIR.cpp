$NetBSD$

--- js/src/jit/MIR.cpp.orig	2016-10-31 20:15:35.000000000 +0000
+++ js/src/jit/MIR.cpp
@@ -76,7 +76,7 @@ MDefinition::PrintOpcodeName(GenericPrin
     const char* name = names[op];
     size_t len = strlen(name);
     for (size_t i = 0; i < len; i++)
-        out.printf("%c", tolower(name[i]));
+        out.printf("%c", tolower((unsigned char)name[i]));
 }
 
 static MConstant*
