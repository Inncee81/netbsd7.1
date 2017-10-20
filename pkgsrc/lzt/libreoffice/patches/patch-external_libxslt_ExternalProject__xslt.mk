$NetBSD$

--- external/libxslt/ExternalProject_xslt.mk.orig	2016-07-26 21:17:25.000000000 +0000
+++ external/libxslt/ExternalProject_xslt.mk
@@ -34,7 +34,7 @@ $(call gb_ExternalProject_get_state_targ
 			$(if $(MSVC_USE_DEBUG_RUNTIME),cruntime=/MDd) \
 			vcmanifest=yes \
 			lib=$(call gb_UnpackedTarball_get_dir,xml2)/win32/bin.msvc \
-		&& unset MAKEFLAGS \
+		&& unset MAKEFLAGS || true \
 		&& LIB="$(ILIB)" nmake \
 	,win32)
 endif
