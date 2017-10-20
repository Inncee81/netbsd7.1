$NetBSD$

--- libhack/alias_nbt.c.orig	2000-08-31 12:54:55.000000000 +0000
+++ libhack/alias_nbt.c
@@ -102,7 +102,7 @@ static void PrintRcode( u_char rcode )  
 		case CFT_ERR:
 			printf("\nName in conflict error.\n");
 		default:
-			printf("\n???=%0x\n", rcode );
+			printf("\n??? = %0x\n", rcode );
 
 	}	
 }
