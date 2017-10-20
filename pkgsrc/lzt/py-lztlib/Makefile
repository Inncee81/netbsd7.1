PKGNAME=	${PYPKGPREFIX}-lztlib-1.0
DISTNAME=
CATEGORIES=	lzt
MASTER_SITES=

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://www.k1.com.br/
COMMENT=	various widget to use in PYGTK

WRKSRC=		${WRKDIR}/${PKGNAME}

do-extract:
	mkdir -p ${WRKSRC};cd ${FILESDIR};find setup.py lztlib | grep -v CVS | cpio -pdvm ${WRKSRC}

DEPENDS+=       ${PYPKGPREFIX}-sqlite3>0:../../databases/py-sqlite3
DEPENDS+=       ${PYPKGPREFIX}-psycopg2>0:../../databases/py-psycopg2
DEPENDS+=       ${PYPKGPREFIX}-beautifulsoup4>0:../../www/py-beautifulsoup4
DEPENDS+=       ${PYPKGPREFIX}-gnome2>0:../../x11/py-gnome2
DEPENDS+=       ${PYPKGPREFIX}-sysctl>0:../../devel/py-sysctl
DEPENDS+=       glade:../../devel/glade

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
