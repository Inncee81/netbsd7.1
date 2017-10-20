$NetBSD$

--- sc/source/core/opencl/formulagroupcl.cxx.orig	2016-07-26 21:17:25.000000000 +0000
+++ sc/source/core/opencl/formulagroupcl.cxx
@@ -103,6 +103,12 @@ const unsigned long __nan[2] = {0xffffff
 
 #include <memory>
 
+static char *to_string_i(int i) {
+	static char area[64];
+	snprintf(area,sizeof(area),"%d",i);
+	return area;
+}
+
 using namespace formula;
 
 namespace sc { namespace opencl {
@@ -142,7 +148,7 @@ std::string StackVarEnumToString(StackVa
         CASE(Unknown);
 #undef CASE
     }
-    return std::to_string(static_cast<int>(e));
+    return to_string_i(static_cast<int>(e));
 }
 
 std::string linenumberify(const std::string& s)
@@ -2627,6 +2633,7 @@ DynamicKernelSoPArguments::DynamicKernel
             case ocPush:
                 if (pChild->GetType() == formula::svDoubleVectorRef)
                 {
+		    char area[1024];
                     const formula::DoubleVectorRefToken* pDVR =
                         static_cast<const formula::DoubleVectorRefToken*>(pChild);
 
@@ -2640,8 +2647,10 @@ DynamicKernelSoPArguments::DynamicKernel
                     // CL_DEVICE_MAX_PARAMETER_SIZE is 256, which for 32-bit code probably means 64
                     // of them. Round down a bit.
 
-                    if (pDVR->GetArrays().size() > 50)
-                        throw UnhandledToken(pChild, ("Kernel would have ridiculously many parameters (" + std::to_string(2 + pDVR->GetArrays().size()) + ")").c_str());
+                    if (pDVR->GetArrays().size() > 50) {
+                        snprintf(area,sizeof(area),"Kernel would have ridiculously many parameters (%d)",(2 + pDVR->GetArrays().size()));
+                        throw UnhandledToken(pChild, area);
+		    }
 
                     for (size_t j = 0; j < pDVR->GetArrays().size(); ++j)
                     {
