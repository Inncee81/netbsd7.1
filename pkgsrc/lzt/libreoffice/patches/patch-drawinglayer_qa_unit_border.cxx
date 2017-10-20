$NetBSD$

--- drawinglayer/qa/unit/border.cxx.orig	2016-07-26 21:17:25.000000000 +0000
+++ drawinglayer/qa/unit/border.cxx
@@ -135,7 +135,7 @@ void DrawinglayerBorderTest::testDoubleP
             nHeight = rPolyPolygon.GetBoundRect().getHeight();
         }
     }
-    sal_Int32 nExpectedHeight = std::round(fRightWidth);
+    sal_Int32 nExpectedHeight = round(fRightWidth);
     // This was 2, and should be 1: if the logical requested width is 1.47,
     // then that must be 1 px on the screen, not 2.
     CPPUNIT_ASSERT_EQUAL(nExpectedHeight, nHeight);
