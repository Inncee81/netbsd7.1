# $NetBSD$

GITHUB_PROJECT=	pipeglade
DISTNAME=	4.7.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=trebb/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nerevoso@k1.com.br
HOMEPAGE=	https://github.com/trebb/pipeglade/
COMMENT=	Graphical User Interfaces, The UNIX Way

EGDIR=			${LOCALBASE}/share/examples/pipeglade
INSTALLATION_DIRS+=	share/examples/pipeglade ${PKGMANDIR}/man1 bin

WRKSRC=	${WRKDIR}/pipeglade-4.7.0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pipeglade ${DESTDIR}${LOCALBASE}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.sh ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ui ${DESTDIR}${EGDIR}
	cd ${WRKSRC};find widget-examples www-templates | cpio -pdvm ${DESTDIR}${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/*.1 ${DESTDIR}${LOCALBASE}/${PKGMANDIR}/man1

.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
