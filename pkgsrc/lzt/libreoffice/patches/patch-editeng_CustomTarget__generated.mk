$NetBSD$

--- editeng/CustomTarget_generated.mk.orig	2016-07-26 21:17:25.000000000 +0000
+++ editeng/CustomTarget_generated.mk
@@ -19,8 +19,8 @@ $(editeng_INC)/tokens.hxx $(editeng_INC)
 
 $(editeng_INC)/tokens.cxx : $(editeng_INC)/tokens.gperf
 	$(GPERF) --compare-strncmp --readonly-tables --output-file=$(editeng_INC)/tokens.cxx $(editeng_INC)/tokens.gperf
-	sed -i -e "s/(char\*)0/(char\*)0, XML_TOKEN_INVALID/g" $(editeng_INC)/tokens.cxx
-	sed -i -e "/^#line/d" $(editeng_INC)/tokens.cxx
+	gsed -i-e "s/(char\*)0/(char\*)0, XML_TOKEN_INVALID/g" $(editeng_INC)/tokens.cxx
+	gsed -i-e "/^#line/d" $(editeng_INC)/tokens.cxx
 
 $(call gb_CustomTarget_get_target,editeng/generated) : $(editeng_INC)/tokens.cxx
 
