PKGNAME=	adminpassword-1.0
CATEGORIES=	sysutils
MASTER_SITES=
DISTNAME=

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://www.k1.com.br/
COMMENT=	asks admin passwword on first time boot
INSTALL_UNSTRIPPED=		yes

WRKSRC=		${WRKDIR}/${PKGNAME}

INSTALLATION_DIRS=	etc/adminpassword

RCD_SCRIPTS=		adminpassword

do-extract:
	mkdir -p ${WRKSRC}
	cd ${FILESDIR};find src \! -name "CVS/*" | cpio -pdvm ${WRKSRC}

do-build:
	cd ${WRKSRC}/src;\
		make makeadminpassword
do-install:
	cd ${WRKSRC}/src;\
	${INSTALL_PROGRAM} makeadminpassword \
		${DESTDIR}${LOCALBASE}/etc/adminpassword 

.include "../../misc/dialog/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit

dorsync:
	cd ..;sh dorsyncpackages moreutils
