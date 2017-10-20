$NetBSD$

--- libretroshare/src/rsserver/rsloginhandler.cc.orig	2016-08-31 11:24:02.000000000 +0000
+++ libretroshare/src/rsserver/rsloginhandler.cc
@@ -4,7 +4,7 @@
 #include "rsloginhandler.h"
 #include "util/rsdir.h"
 #include "rsaccounts.h"
-#if defined(HAS_GNOME_KEYRING) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(HAS_GNOME_KEYRING) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <gnome-keyring-1/gnome-keyring.h>
 
 GnomeKeyringPasswordSchema my_schema = {
@@ -122,9 +122,9 @@ bool RsLoginHandler::tryAutoLogin(const 
 	/******************************** WINDOWS/UNIX SPECIFIC PART ******************/
 #ifndef __HAIKU__
 #ifndef WINDOWS_SYS /* UNIX */
-#if defined(HAS_GNOME_KEYRING) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(HAS_GNOME_KEYRING) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined (__NetBSD__)
 
-	gchar *passwd = NULL;
+	char *passwd = NULL;
 
 	std::cerr << "Using attribute: " << ssl_id << std::endl;
 	if( gnome_keyring_find_password_sync(&my_schema, &passwd,"RetroShare SSL Id",ssl_id.toStdString().c_str(),NULL) == GNOME_KEYRING_RESULT_OK )
@@ -373,7 +373,7 @@ bool RsLoginHandler::enableAutoLogin(con
 	/******************************** WINDOWS/UNIX SPECIFIC PART ******************/
 #ifndef __HAIKU__
 #ifndef WINDOWS_SYS /* UNIX */
-#if defined(HAS_GNOME_KEYRING) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(HAS_GNOME_KEYRING) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
 	if(GNOME_KEYRING_RESULT_OK == gnome_keyring_store_password_sync(&my_schema, NULL, (gchar*)("RetroShare password for SSL Id "+ssl_id.toStdString()).c_str(),(gchar*)ssl_passwd.c_str(),"RetroShare SSL Id",ssl_id.toStdString().c_str(),NULL)) 
 	{
 		std::cerr << "Stored passwd " << "************************" << " into gnome keyring" << std::endl;
