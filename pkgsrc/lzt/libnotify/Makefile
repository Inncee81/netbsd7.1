# $NetBSD: Makefile,v 1.37 2016/08/03 10:22:19 adam Exp $

DISTNAME=	libnotify-0.7.6
PKGREVISION=	3
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libnotify/0.7/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.gnome.org/libnotify/
COMMENT=	Desktop notification framework
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	libnotify07-[0-9]*
SUPERSEDES+=	libnotify07-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	libnotify.pc.in

.include "options.mk"

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
