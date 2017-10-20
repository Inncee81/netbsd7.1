$NetBSD$

--- src/widgets/sp-xmlview-attr-list.cpp.orig	2014-11-30 18:45:32.000000000 +0000
+++ src/widgets/sp-xmlview-attr-list.cpp
@@ -15,6 +15,7 @@
 
 #include <cstring>
 #include <glibmm/i18n.h>
+#include <gtk/gtk.h>
 
 #include "helper/sp-marshal.h"
 #include "../xml/node-event-vector.h"
