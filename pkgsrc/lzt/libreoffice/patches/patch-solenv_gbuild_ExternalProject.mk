$NetBSD$

--- solenv/gbuild/ExternalProject.mk.orig	2016-07-26 21:17:25.000000000 +0000
+++ solenv/gbuild/ExternalProject.mk
@@ -218,7 +218,7 @@ define gb_ExternalProject_run
 $(if $(findstring YES,$(UNPACKED_IS_BIN_TARBALL)),\
 	touch $@,
 $(call gb_Helper_print_on_error,cd $(EXTERNAL_WORKDIR)/$(3) && \
-	unset Platform && \
+	unset Platform || true && \
 	$(if $(WRAPPERS),export $(WRAPPERS) &&) \
 	$(if $(NMAKE),INCLUDE="$(gb_ExternalProject_INCLUDE)" LIB="$(ILIB)" MAKEFLAGS=) \
 	$(2) && touch $@,$(EXTERNAL_WORKDIR)/$(if $(3),$(3)/,)$(if $(4),$(4),$(1).log))
