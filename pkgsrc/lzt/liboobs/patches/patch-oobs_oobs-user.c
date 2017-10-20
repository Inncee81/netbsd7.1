$NetBSD$

--- oobs/oobs-user.c.orig	2009-09-05 14:00:45.000000000 +0000
+++ oobs/oobs-user.c
@@ -18,13 +18,29 @@
  * Authors: Carlos Garnacho Parro  <carlosg@gnome.org>
  */
 
+#if defined(HAVE_CONFIG_H)
+#include <config.h>
+#endif
+
 #include <glib-object.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef HAVE_CRYPT_H
 #include <crypt.h>
+#endif
+#ifndef __NetBSD__
 #include <utmp.h>
+#define UTMP utmp
+#define GETUTENT getutent
+#define ENDUTENT endutent
+#else
+#include <utmpx.h>
+#define UTMP utmpx
+#define GETUTENT getutxent
+#define ENDUTENT endutxent
+#endif
 
 #include "oobs-usersconfig.h"
 #include "oobs-user.h"
@@ -811,7 +827,7 @@ oobs_user_set_other_data (OobsUser *user
 gboolean
 oobs_user_get_active (OobsUser *user)
 {
-  struct utmp *entry;
+  struct UTMP *entry;
   const gchar *login;
   gboolean match = FALSE;
 
@@ -819,14 +835,16 @@ oobs_user_get_active (OobsUser *user)
 
   login = oobs_user_get_login_name (user);
 
-  while (!match && (entry = getutent ()) != NULL)
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
+  while (!match && (entry = GETUTENT ()) != NULL)
     {
       match = (entry->ut_type == USER_PROCESS &&
 	       strcmp (entry->ut_user, login) == 0);
     }
 
   /* close utmp */
-  endutent ();
+  ENDUTENT ();
 
   return match;
+#endif
 }
