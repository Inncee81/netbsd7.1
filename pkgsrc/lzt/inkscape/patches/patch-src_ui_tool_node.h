$NetBSD$

--- src/ui/tool/node.h.orig	2014-11-30 18:45:32.000000000 +0000
+++ src/ui/tool/node.h
@@ -21,11 +21,7 @@
 #include <stdexcept>
 #include <cstddef>
 
-#if __cplusplus >= 201103L
 #include <functional>
-#else
-#include <tr1/functional>
-#endif
 
 #include <boost/enable_shared_from_this.hpp>
 #include <boost/shared_ptr.hpp>
