$NetBSD$

--- drawinglayer/source/primitive2d/borderlineprimitive2d.cxx.orig	2016-07-26 21:17:25.000000000 +0000
+++ drawinglayer/source/primitive2d/borderlineprimitive2d.cxx
@@ -216,7 +216,7 @@ primitive2d::Primitive2DReference makeSo
                             getStart(), getEnd(), aVector, getRGBColorLeft(), 0.0);
                     else
                     {
-                        double fWidth = bPixelCorrection ? std::round(fLeftWidth) : fLeftWidth;
+                        double fWidth = bPixelCorrection ? round(fLeftWidth) : fLeftWidth;
                         xRetval[0] = makeSolidLinePrimitive(
                             aClipRegion, aTmpStart, aTmpEnd, aVector, getRGBColorLeft(), fWidth, -fLeftWidth/2.0);
                     }
@@ -228,7 +228,7 @@ primitive2d::Primitive2DReference makeSo
                             getStart(), getEnd(), aVector, getRGBColorRight(), fLeftWidth+mfDistance);
                     else
                     {
-                        double fWidth = bPixelCorrection ? std::round(fRightWidth) : fRightWidth;
+                        double fWidth = bPixelCorrection ? round(fRightWidth) : fRightWidth;
                         xRetval[1] = makeSolidLinePrimitive(
                             aClipRegion, aTmpStart, aTmpEnd, aVector, getRGBColorRight(), fWidth, mfDistance+fRightWidth/2.0);
                     }
