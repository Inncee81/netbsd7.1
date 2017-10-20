$NetBSD$

--- nss/lib/freebl/config.mk.orig	2016-11-29 01:03:38.000000000 +0000
+++ nss/lib/freebl/config.mk
@@ -90,8 +90,4 @@ EXTRA_SHARED_LIBS += \
 endif
 endif
 
-ifeq ($(OS_ARCH), Darwin)
-EXTRA_SHARED_LIBS += -dylib_file @executable_path/libplc4.dylib:$(DIST)/lib/libplc4.dylib -dylib_file @executable_path/libplds4.dylib:$(DIST)/lib/libplds4.dylib
-endif
-
 endif
