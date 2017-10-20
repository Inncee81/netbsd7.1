$NetBSD$

--- vcl/workben/vcldemo.cxx.orig	2016-07-26 21:17:25.000000000 +0000
+++ vcl/workben/vcldemo.cxx
@@ -424,14 +424,14 @@ public:
                 {
                     float nFontMagnitude = 0.25f;
                     // random font size to avoid buffering
-                    nFontHeight = 1 + nFontMagnitude * (0.9 + comphelper::rng::uniform_real_distribution(0.0, std::nextafter(0.1, DBL_MAX))) * (r.Bottom() - r.Top());
+                    nFontHeight = 1 + nFontMagnitude * (0.9 + comphelper::rng::uniform_real_distribution(0.0, nextafter(0.1, DBL_MAX))) * (r.Bottom() - r.Top());
                     nFontIndex=0;
                     nFontColorIndex=0;
                 }
                 else
                 {
                     // random font size to avoid buffering
-                    nFontHeight = 1 + i * (0.9 + comphelper::rng::uniform_real_distribution(0.0, std::nextafter(0.1, DBL_MAX))) * (r.Top() - r.Bottom()) / nPrintNumCopies;
+                    nFontHeight = 1 + i * (0.9 + comphelper::rng::uniform_real_distribution(0.0, nextafter(0.1, DBL_MAX))) * (r.Top() - r.Bottom()) / nPrintNumCopies;
                     nFontIndex = (i % maFontNames.size());
                     nFontColorIndex=(i % maFontNames.size());
                 }
