PKGNAME=	caja-thumbnailers-1.0
CATEGORIES=	lzt
DISTNAME=
MASTER_SITES=

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://www.k1.com.br/
COMMENT=	Thumbnailers for mate-desktop caja

WRKSRC=		${WRKDIR}/${PKGNAME}

pre-patch:
	mkdir -p ${WRKSRC}

pre-configure:
	mkdir -p ${WRKSRC}
	cp -rpf ${FILESDIR}/* ${WRKSRC}

post-install:
	cd ${FILESDIR};find * | grep -v CVS |cpio -pdvm ${DESTDIR}

.include "../../graphics/dia/buildlink3.mk"
.include "../../multimedia/ffmpegthumbnailer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

makeplist:
	make print-PLIST | grep -v CVS > PLIST

cvs:
	cvs up
	cvs commit
