$NetBSD$

--- external/libxml2/ExternalProject_xml2.mk.orig	2016-07-26 21:17:25.000000000 +0000
+++ external/libxml2/ExternalProject_xml2.mk
@@ -34,7 +34,7 @@ $(call gb_ExternalProject_get_state_targ
 	$(call gb_ExternalProject_run,build,\
 		cscript configure.js \
 			iconv=no icu=yes sax1=yes $(if $(MSVC_USE_DEBUG_RUNTIME),run_debug=yes cruntime=/MDd) \
-		&& unset MAKEFLAGS \
+		&& unset MAKEFLAGS || true \
 		&& LIB="$(ILIB)" nmake \
 	,win32)
 endif
