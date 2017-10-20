$NetBSD$

--- plugins/VOIP/gui/VideoProcessor.cpp.orig	2016-08-31 11:24:02.000000000 +0000
+++ plugins/VOIP/gui/VideoProcessor.cpp
@@ -737,7 +737,7 @@ bool FFmpegVideo::decodeData(const RsVOI
 	//Mac OS X appears to be 16-byte mem aligned.
 	unsigned char *tmp = (unsigned char*)malloc(s + AV_INPUT_BUFFER_PADDING_SIZE) ;
 #else //MAC
-	unsigned char *tmp = (unsigned char*)memalign(16, s + AV_INPUT_BUFFER_PADDING_SIZE) ;
+	unsigned char *tmp = (unsigned char*)malloc(s + AV_INPUT_BUFFER_PADDING_SIZE) ;
 #endif //MAC
 #endif //MINGW
 	if (tmp == NULL) {
