$NetBSD$

--- FlPosteRazorDialog.cpp.orig	2017-03-09 21:23:42.000000000 +0000
+++ FlPosteRazorDialog.cpp
@@ -29,6 +29,7 @@
 #include <FL/x.H>
 #include <FL/Fl_Native_File_Chooser.H>
 #include "TranslationConstants.h"
+#include <unistd.h>
 
 
 #if defined (WIN32)
