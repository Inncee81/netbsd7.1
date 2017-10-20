$NetBSD$

--- vcl/source/filter/sgvspln.cxx.orig	2016-07-26 21:17:25.000000000 +0000
+++ vcl/source/filter/sgvspln.cxx
@@ -583,16 +583,16 @@ sal_uInt16 ParaSpline(sal_uInt16 n, doub
         case 4: {
             if (std::abs(Marg01)>=MAXROOT) {
                 alphX=0.0;
-                alphY=std::copysign(1.0,y[1]-y[0]);
+                alphY=copysign(1.0,y[1]-y[0]);
             } else {
-                alphX=std::copysign(sqrt(1.0/(1.0+Marg01*Marg01)),x[1]-x[0]);
+                alphX=copysign(sqrt(1.0/(1.0+Marg01*Marg01)),x[1]-x[0]);
                 alphY=alphX*Marg01;
             }
             if (std::abs(MargN1)>=MAXROOT) {
                 betX=0.0;
-                betY=std::copysign(1.0,y[n]-y[n-1]);
+                betY=copysign(1.0,y[n]-y[n-1]);
             } else {
-                betX=std::copysign(sqrt(1.0/(1.0+MargN1*MargN1)),x[n]-x[n-1]);
+                betX=copysign(sqrt(1.0/(1.0+MargN1*MargN1)),x[n]-x[n-1]);
                 betY=betX*MargN1;
             }
         }
