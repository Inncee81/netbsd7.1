$NetBSD$

--- applets/clock/calendar-client.c.orig	2010-02-09 12:32:08.000000000 +0000
+++ applets/clock/calendar-client.c
@@ -2123,7 +2123,7 @@ calendar_client_set_task_completed (Cale
     {
       struct icaltimetype  completed_time;
 
-      completed_time = icaltime_current_time_with_zone (client->priv->zone);
+      completed_time = icaltime_current_time_with_zone (icaltimezone_get_utc_timezone ());
       if (!prop)
 	{
 	  icalcomponent_add_property (ical,
