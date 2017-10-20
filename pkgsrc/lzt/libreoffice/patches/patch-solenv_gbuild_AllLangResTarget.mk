$NetBSD$

--- solenv/gbuild/AllLangResTarget.mk.orig	2016-07-26 21:17:25.000000000 +0000
+++ solenv/gbuild/AllLangResTarget.mk
@@ -88,7 +88,6 @@ $(call gb_Helper_abbreviate_dirs,\
 	echo "-s \
 		$(INCLUDE) \
 		-I$(dir $(3)) \
-		$(DEFS) \
 		-fp=$(1) \
 		$(if $(MERGEDFILE),$(MERGEDFILE),$<)" > $${RESPONSEFILE} && \
 	$(gb_ResTarget_RSCCOMMAND) -presponse @$${RESPONSEFILE} && \
