$NetBSD$

--- parserInternals.c.orig	2016-05-23 07:25:25.000000000 +0000
+++ parserInternals.c
@@ -1438,6 +1438,11 @@ xmlNewEntityInputStream(xmlParserCtxtPtr
                 break;
             case XML_EXTERNAL_GENERAL_PARSED_ENTITY:
             case XML_EXTERNAL_PARAMETER_ENTITY:
+		if (((ctxt->options & XML_PARSE_NOENT) == 0) &&
+		    ((ctxt->options & XML_PARSE_DTDVALID) == 0)) {
+		    xmlErrInternal(ctxt, "xmlNewEntityInputStream will not read content for external entity\n",
+				    NULL);
+		}
 		return(xmlLoadExternalEntity((char *) entity->URI,
 		       (char *) entity->ExternalID, ctxt));
             case XML_INTERNAL_GENERAL_ENTITY:
