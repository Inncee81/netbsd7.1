$NetBSD$

--- youtube_dl/postprocessor/ffmpeg.py.orig	2017-03-16 01:41:18.000000000 +0000
+++ youtube_dl/postprocessor/ffmpeg.py
@@ -64,7 +64,7 @@ class FFmpegPostProcessor(PostProcessor)
         return FFmpegPostProcessor(downloader)._versions
 
     def _determine_executables(self):
-        programs = ['avprobe', 'avconv', 'ffmpeg', 'ffprobe']
+        programs = ['avprobe', 'avconv', 'ffmpeg3', 'ffprobe3']
         prefer_ffmpeg = False
 
         self.basename = None
