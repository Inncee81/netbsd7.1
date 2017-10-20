$NetBSD$

--- sw/CustomTarget_generated.mk.orig	2016-07-26 21:17:25.000000000 +0000
+++ sw/CustomTarget_generated.mk
@@ -26,8 +26,8 @@ $(sw_INC)/tokens.cxx : $(sw_INC)/TextBlo
 	--class-name=TextBlockTokens --word-array-name=textBlockList --enum $(sw_INC)/TextBlockTokens.gperf
 	$(GPERF) --compare-strncmp --readonly-tables -T $(sw_INC)/BlockListTokens.gperf \
 	--class-name=BlockListTokens --word-array-name=blockListList >> $(sw_INC)/tokens.cxx
-	sed -i -e "s/(char\*)0/(char\*)0, XML_TOKEN_INVALID/g" $(sw_INC)/tokens.cxx
-	sed -i -e "/^#line/d" $(sw_INC)/tokens.cxx
+	gsed -i-e "s/(char\*)0/(char\*)0, XML_TOKEN_INVALID/g" $(sw_INC)/tokens.cxx
+	gsed -i-e "/^#line/d" $(sw_INC)/tokens.cxx
 
 $(call gb_CustomTarget_get_target,sw/generated) : $(sw_INC)/tokens.cxx
 
