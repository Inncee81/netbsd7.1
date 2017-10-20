$NetBSD$

--- external/openssl/ExternalProject_openssl.mk.orig	2016-07-26 21:17:25.000000000 +0000
+++ external/openssl/ExternalProject_openssl.mk
@@ -68,7 +68,7 @@ $(call gb_ExternalProject_get_state_targ
 		&& export LIB="$(ILIB)" \
 		&& $(PERL) Configure $(OPENSSL_PLATFORM) no-idea \
 		&& cmd /c "ms\do_ms.bat $(PERL) $(OPENSSL_PLATFORM)" \
-		&& unset MAKEFLAGS \
+		&& unset MAKEFLAGS || true \
 		&& nmake -f "ms\ntdll.mak" \
 		&& mv inc32/* include/ \
 	))
@@ -76,7 +76,7 @@ $(call gb_ExternalProject_get_state_targ
 else
 $(call gb_ExternalProject_get_state_target,openssl,build):
 	$(call gb_ExternalProject_run,build,\
-		unset MAKEFLAGS && \
+		unset MAKEFLAGS || true && \
 		$(if $(filter LINUX MACOSX FREEBSD ANDROID SOLARIS IOS,$(OS)), \
 			./Configure, \
 		$(if $(filter WNT,$(OS)), \
