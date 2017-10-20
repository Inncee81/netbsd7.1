$NetBSD$

--- display.c.orig	1998-08-24 04:51:48.000000000 +0000
+++ display.c
@@ -54,6 +54,7 @@ int page_size;
 static int l_nflag, l_eflag;
 static int n_entries;
 static int err_pos;
+extern struct t_entry t_mask;  /* traffic mask */
 
 void
 init_display(reinit)
@@ -282,6 +283,13 @@ collect(e)
 	packets_total++;
 	bytes_total += e->bytes;
 	j = page * page_size;
+
+	e->src.s_addr &= t_mask.src.s_addr;
+	e->dst.s_addr &= t_mask.dst.s_addr;
+	e->sport &= t_mask.sport;
+	e->dport &= t_mask.dport;
+	e->proto &= t_mask.proto;
+
 	for (i = 0; i < n_entry; i++) {
 		if (memcmp(&e->eh, &entries[i].eh, sizeof(e->eh)) == 0 &&
 		    e->src.s_addr == entries[i].src.s_addr &&
