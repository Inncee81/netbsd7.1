$NetBSD$

--- netwerk/sctp/src/netinet6/sctp6_usrreq.c.orig	2016-05-12 17:13:28.000000000 +0000
+++ netwerk/sctp/src/netinet6/sctp6_usrreq.c
@@ -471,8 +471,6 @@ sctp6_notify(struct sctp_inpcb *inp,
 	    (icmph->icmp6_code == ICMP_UNREACH_HOST_PROHIB) ||
 #if defined(__Panda__)
             (icmph->icmp6_code == ICMP_UNREACH_ADMIN)) {
-#elif defined(__Userspace_os_NetBSD)
-            (icmph->icmp6_code == ICMP_UNREACH_ADMIN_PROHIBIT)) {
 #else
             (icmph->icmp6_code == ICMP_UNREACH_FILTER_PROHIB)) {
 #endif
