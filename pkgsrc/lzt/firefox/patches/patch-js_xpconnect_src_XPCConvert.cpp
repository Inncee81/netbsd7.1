$NetBSD$

--- js/xpconnect/src/XPCConvert.cpp.orig	2016-10-31 20:15:38.000000000 +0000
+++ js/xpconnect/src/XPCConvert.cpp
@@ -136,7 +136,7 @@ XPCConvert::NativeData2JS(MutableHandleV
         d.setNumber(*static_cast<const float*>(s));
         return true;
     case nsXPTType::T_DOUBLE:
-        d.setNumber(*static_cast<const double*>(s));
+        d.setNumber(CanonicalizeNaN(*static_cast<const double*>(s)));
         return true;
     case nsXPTType::T_BOOL  :
         d.setBoolean(*static_cast<const bool*>(s));
