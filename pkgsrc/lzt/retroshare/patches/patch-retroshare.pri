$NetBSD$

--- retroshare.pri.orig	2016-08-31 11:24:02.000000000 +0000
+++ retroshare.pri
@@ -3,18 +3,30 @@
 #CONFIG *= libresapilocalserver
 
 # To {dis,en}able libresapi via HTTP (libmicrohttpd) {,un}comment the following line
-CONFIG *= libresapihttpserver
+CONFIG *= libresapihttpserver
 
 # Gxs is always enabled now.
 DEFINES *= RS_ENABLE_GXS
 
 unix {
-	isEmpty(PREFIX)   { PREFIX   = "/usr" }
-	isEmpty(BIN_DIR)  { BIN_DIR  = "$${PREFIX}/bin" }
-	isEmpty(INC_DIR)  { INC_DIR  = "$${PREFIX}/include/retroshare06" }
-	isEmpty(LIB_DIR)  { LIB_DIR  = "$${PREFIX}/lib" }
-	isEmpty(DATA_DIR) { DATA_DIR = "$${PREFIX}/share/RetroShare06" }
-	isEmpty(PLUGIN_DIR) { PLUGIN_DIR  = "$${LIB_DIR}/retroshare/extensions6" }
+	PREFIX   = "/usr/pkg"
+	BIN_DIR  = "$${PREFIX}/bin"
+	DATA_DIR = "$${PREFIX}/share/RetroShare06"
+	PLUGIN_DIR  = "$${PREFIX}/lib/retroshare/extensions6"
+	DEFINES += "fseeko64=fseeko"
+	DEFINES += "ftello64=ftello"
+	DEFINES += "fopen64=fopen"
+	DEFINES += "stat64=stat"
+	DEFINES += "QTDIR=$$QTDIR"
+	DEFINES += "statvfs64=statvfs"
+	DEFINES += "memalign=posix_memalign"
+	QMAKE_CFLAGS += $$system(pkg-config --cflags QtGui QtCore glib-2.0 sqlcipher libxml-2.0 libavutil \
+		libupnp libavcodec gnome-keyring-1 openssl cryptui-0.0) 
+	QMAKE_CXXFLAGS = $$QMAKE_CFLAGS
+	LIBS -= -lsqlite3
+	QMAKE_LFLAGS += $$system(pkg-config --libs sqlcipher glib-2.0 libxml-2.0 libavutil \
+		libavcodec libupnp gnome-keyring-1 openssl cryptui-0.0 QtGui QtCore)
+	CONFIG += upnp_libupnp
 }
 
 android-g++ {
