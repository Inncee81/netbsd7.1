$NetBSD$

--- src/extension/internal/pdfinput/pdf-parser.h.orig	2014-11-30 18:45:32.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.h
@@ -26,7 +26,7 @@ namespace Inkscape {
 using Inkscape::Extension::Internal::SvgBuilder;
 
 #include "goo/gtypes.h"
-#include "Object.h"
+#include "poppler/Object.h"
 
 class GooString;
 class XRef;
