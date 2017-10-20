# $NetBSD: options.mk,v 1.6 2015/07/23 20:54:54 markd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib mng pdf svg python
PKG_SUGGESTED_OPTIONS=	mng svg pdf python

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		aalib mng pdf svg python

.if !empty(PKG_OPTIONS:Mpython)
.include "../../x11/py-gtk2/buildlink3.mk"
PLIST.python=		yes
CONFIGURE_ARGS+=       --enable-python
.else
CONFIGURE_ARGS+=       --disable-python
.endif

.if !empty(PKG_OPTIONS:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
PLIST.aalib=		yes
.endif

.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
PLIST.mng=		yes
.endif

.if !empty(PKG_OPTIONS:Mpdf)
.include "../../print/poppler-glib/buildlink3.mk"
PLIST.pdf=		yes
.endif

.if !empty(PKG_OPTIONS:Msvg)
.include "../../graphics/librsvg/buildlink3.mk"
PLIST.svg=		yes
.endif
