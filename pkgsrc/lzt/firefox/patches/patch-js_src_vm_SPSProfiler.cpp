$NetBSD$

--- js/src/vm/SPSProfiler.cpp.orig	2016-10-31 20:15:37.000000000 +0000
+++ js/src/vm/SPSProfiler.cpp
@@ -4,6 +4,8 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#include "jscntxtinlines.h"
+
 #include "vm/SPSProfiler.h"
 
 #include "mozilla/DebugOnly.h"
