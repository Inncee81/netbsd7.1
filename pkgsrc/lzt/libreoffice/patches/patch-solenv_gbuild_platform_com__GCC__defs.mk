$NetBSD$

--- solenv/gbuild/platform/com_GCC_defs.mk.orig	2016-07-26 21:17:25.000000000 +0000
+++ solenv/gbuild/platform/com_GCC_defs.mk
@@ -107,9 +107,9 @@ endif
 gb_CXXFLAGS_COMMON += $(gb_VISIBILITY_FLAGS_CXX)
 
 ifeq ($(HAVE_GCC_STACK_PROTECTOR_STRONG),TRUE)
-gb_CFLAGS_COMMON += -fstack-protector-strong
-gb_CXXFLAGS_COMMON += -fstack-protector-strong
-gb_LinkTarget_LDFLAGS += -fstack-protector-strong
+gb_CFLAGS_COMMON += -fno-stack-protector
+gb_CXXFLAGS_COMMON += -fno-stack-protector
+gb_LinkTarget_LDFLAGS += -fno-stack-protector
 endif
 
 gb_CFLAGS_WERROR := $(if $(ENABLE_WERROR),-Werror)
