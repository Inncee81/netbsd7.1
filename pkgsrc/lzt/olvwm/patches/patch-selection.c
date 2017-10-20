$NetBSD$

--- selection.c.orig	1998-01-13 21:00:57.000000000 +0000
+++ selection.c
@@ -299,10 +299,8 @@ IsSelected(cli)
  * Add this client to the list of clients on the PRIMARY selection and mark
  * the client as being selected.  Acquires the PRIMARY selection if necessary.
  */
-int
-AddSelection(cli, timestamp)
-	Client *cli;
-	Time timestamp;
+void
+AddSelection(Client *cli, Time timestamp)
 {
 	List *l = selectList;
 	Client *tc;
