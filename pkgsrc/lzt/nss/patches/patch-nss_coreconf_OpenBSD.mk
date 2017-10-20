$NetBSD$

--- nss/coreconf/OpenBSD.mk.orig	2016-11-29 01:03:38.000000000 +0000
+++ nss/coreconf/OpenBSD.mk
@@ -24,7 +24,7 @@ OS_LIBS			+= -pthread
 DSO_LDOPTS		+= -pthread
 endif
 
-DLL_SUFFIX		= so.1.0
+DLL_SUFFIX		= so
 
 OS_CFLAGS		= $(DSO_CFLAGS) $(OS_REL_CFLAGS) -Wall -Wno-switch -pipe -DOPENBSD
 
