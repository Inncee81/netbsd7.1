$NetBSD$

--- slideshow/source/engine/OGLTrans/generic/OGLTrans_TransitionImpl.cxx.orig	2016-07-26 21:17:25.000000000 +0000
+++ slideshow/source/engine/OGLTrans/generic/OGLTrans_TransitionImpl.cxx
@@ -868,7 +868,7 @@ std::shared_ptr<OGLTransitionImpl> makeR
 
 inline double randFromNeg1to1()
 {
-    return comphelper::rng::uniform_real_distribution(-1.0, std::nextafter(1.0, DBL_MAX));
+    return comphelper::rng::uniform_real_distribution(-1.0, nextafter(1.0, DBL_MAX));
 }
 
 // TODO(Q3): extract to basegfx
