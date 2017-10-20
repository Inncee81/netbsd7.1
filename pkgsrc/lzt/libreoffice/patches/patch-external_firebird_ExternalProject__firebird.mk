$NetBSD$

--- external/firebird/ExternalProject_firebird.mk.orig	2016-07-26 21:17:25.000000000 +0000
+++ external/firebird/ExternalProject_firebird.mk
@@ -27,7 +27,7 @@ $(eval $(call gb_ExternalProject_registe
 # do not set LDFLAGS - it is mysteriously not used by firebird on MacOSX
 $(call gb_ExternalProject_get_state_target,firebird,build):
 	$(call gb_ExternalProject_run,build,\
-		unset MAKEFLAGS \
+		unset MAKEFLAGS || true \
 		&& export PKG_CONFIG="" \
 		&& export CPPFLAGS=" \
 			$(if $(SYSTEM_LIBATOMIC_OPS),$(LIBATOMIC_OPS_CFLAGS), \
