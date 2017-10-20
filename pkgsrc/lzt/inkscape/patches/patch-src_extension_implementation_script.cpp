$NetBSD$

--- src/extension/implementation/script.cpp.orig	2014-11-30 18:45:32.000000000 +0000
+++ src/extension/implementation/script.cpp
@@ -83,7 +83,7 @@ Script::interpreter_t const Script::inte
 #ifdef WIN32
         {"python", "python-interpreter", "pythonw" },
 #else
-        {"python", "python-interpreter", "python" },
+        {"python", "python-interpreter", "@PYTHONBIN@" },
 #endif
         {"ruby",   "ruby-interpreter",   "ruby"   },
         {"shell",  "shell-interpreter",  "sh"     },
