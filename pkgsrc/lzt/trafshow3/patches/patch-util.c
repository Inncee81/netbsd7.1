$NetBSD$

--- util.c.orig	1997-09-25 04:37:57.000000000 +0000
+++ util.c
@@ -123,12 +123,18 @@ static struct proto_ent {
 	{ "egp",  IPPROTO_EGP  },
 	{ "ospf", IPPROTO_OSPF },
 	{ "igmp", IPPROTO_IGMP },
+	{ "gre",  IPPROTO_GRE  },
+	{ "gif",  IPPROTO_IPIP },
+	{ "esp",  IPPROTO_ESP  },
 #ifdef	IPPROTO_GGP
 	{ "ggp",  IPPROTO_GGP  },
 #endif
 #ifdef	IPPROTO_ENCAP
 	{ "encap",IPPROTO_ENCAP},
 #endif
+#ifdef	IPPROTO_IPV6
+	{ "ipv6", IPPROTO_IPV6},
+#endif
 	{ "ip",   IPPROTO_IP   },
 	{ "raw",  IPPROTO_RAW  },
 	{ NULL, -1 },
