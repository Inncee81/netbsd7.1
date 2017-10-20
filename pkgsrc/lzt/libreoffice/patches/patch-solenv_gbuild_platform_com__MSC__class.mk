$NetBSD$

--- solenv/gbuild/platform/com_MSC_class.mk.orig	2016-07-26 21:17:25.000000000 +0000
+++ solenv/gbuild/platform/com_MSC_class.mk
@@ -38,7 +38,7 @@ endef
 define gb_CObject__command_pattern
 $(call gb_Helper_abbreviate_dirs,\
 	mkdir -p $(dir $(1)) $(dir $(4)) && \
-	unset INCLUDE && \
+	unset INCLUDE || true && \
 	$(if $(filter YES,$(CXXOBJECT_X64)), $(CXX_X64_BINARY), \
 		$(if $(filter %.c,$(3)), $(gb_CC), $(gb_CXX))) \
 		$(DEFS) \
@@ -76,7 +76,7 @@ define gb_PrecompiledHeader__command
 $(call gb_Output_announce,$(2),$(true),PCH,1)
 $(call gb_Helper_abbreviate_dirs,\
 	mkdir -p $(dir $(1)) $(dir $(call gb_PrecompiledHeader_get_dep_target,$(2))) && \
-	unset INCLUDE && \
+	unset INCLUDE || true && \
 	$(gb_CXX) \
 		$(4) $(5) -Fd$(PDBFILE) \
 		$(if $(EXTERNAL_CODE),,$(gb_DEFS_INTERNAL)) \
@@ -161,7 +161,7 @@ $(call gb_Helper_abbreviate_dirs,\
 		$(foreach extraobjectlist,$(EXTRAOBJECTLISTS),$(shell cat $(extraobjectlist))) \
 		$(PCHOBJS) $(NATIVERES)) && \
 		$(if $(filter $(call gb_Library__get_workdir_linktargetname,merged),$(2)),$(call gb_LinkTarget_MergedResponseFile)) \
-	unset INCLUDE && \
+	unset INCLUDE || true && \
 	$(if $(filter YES,$(LIBRARY_X64)), $(LINK_X64_BINARY), $(gb_LINK)) \
 		$(if $(filter Library CppunitTest,$(TARGETTYPE)),$(gb_Library_TARGETTYPEFLAGS)) \
 		$(if $(filter StaticLibrary,$(TARGETTYPE)),-LIB) \
@@ -424,7 +424,7 @@ endef
 
 define gb_Module_DEBUGRUNCOMMAND
 printf "\nAttach the debugger to soffice.bin\n\n"
-unset VCL_HIDE_WINDOWS && \
+unset VCL_HIDE_WINDOWS || true && \
 OFFICESCRIPT=`mktemp` && \
 printf "$(INSTROOT)/$(LIBO_BIN_FOLDER)/soffice.exe" > $${OFFICESCRIPT} && \
 printf " --norestore --nologo '--accept=pipe,name=$(USER);urp;'\n" >> $${OFFICESCRIPT} && \
@@ -525,7 +525,7 @@ $(call gb_ExternalProject_get_preparatio
 $(call gb_ExternalProject_get_state_target,$(1),$(2)): WRAPPERS := $(gb_AUTOCONF_WRAPPERS)
 endef
 
-# Set INCLUDE and LIB variables and unset MAKEFLAGS when using nmake
+# Set INCLUDE and LIB variables and unset MAKEFLAGS
 #
 # gb_ExternalProject_use_nmake project state_target
 define gb_ExternalProject_use_nmake
