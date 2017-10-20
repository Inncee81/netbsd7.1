$NetBSD$

--- ppp/cbcp.c.orig	2000-07-19 02:10:30.000000000 +0000
+++ ppp/cbcp.c
@@ -560,7 +560,7 @@ cbcp_CheckResponse(struct cbcp *cbcp, st
         }
         return CBCP_ACTION_DOWN;
     }
-    log_Printf(LogPHASE, "Internal CBCP error - agreed on %d ??!?\n",
+    log_Printf(LogPHASE, "Internal CBCP error - agreed on %d ?!?\n",
                (int)cbcp->fsm.type);
     return CBCP_ACTION_DOWN;
   } else if (data->type == CBCP_NONUM && cbcp->fsm.type == CBCP_CLIENTNUM) {
