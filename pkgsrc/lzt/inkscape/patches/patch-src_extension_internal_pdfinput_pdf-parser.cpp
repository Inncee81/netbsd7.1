$NetBSD$

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2015-01-18 01:43:07.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -41,7 +41,7 @@ extern "C" {
 #include "goo/GooHash.h"
 #include "GlobalParams.h"
 #include "CharTypes.h"
-#include "Object.h"
+#define POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API 1
 #include "Array.h"
 #include "Dict.h"
 #include "Stream.h"
