$NetBSD$

--- ppp/ip.c.orig	2000-11-07 05:45:44.000000000 +0000
+++ ppp/ip.c
@@ -656,8 +656,8 @@ PacketCheck(struct bundle *bundle, unsig
                "ESP: %s ---> ", inet_ntoa(pip->ip_src));
       loglen += strlen(logbuf + loglen);
       snprintf(logbuf + loglen, sizeof logbuf - loglen,
-               "%s, spi %08x", inet_ntoa(pip->ip_dst),
-               (u_int32_t) ptop);
+               "%s, spi %p", inet_ntoa(pip->ip_dst),
+               ptop);
       loglen += strlen(logbuf + loglen);
     }
     break;
@@ -668,8 +668,8 @@ PacketCheck(struct bundle *bundle, unsig
                "AH: %s ---> ", inet_ntoa(pip->ip_src));
       loglen += strlen(logbuf + loglen);
       snprintf(logbuf + loglen, sizeof logbuf - loglen,
-               "%s, spi %08x", inet_ntoa(pip->ip_dst),
-               (u_int32_t) (ptop + sizeof(u_int32_t)));
+               "%s, spi %p", inet_ntoa(pip->ip_dst),
+               (ptop + sizeof(u_int32_t)));
       loglen += strlen(logbuf + loglen);
     }
     break;
