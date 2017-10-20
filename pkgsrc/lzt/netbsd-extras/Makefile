PKGNAME=	netbsd-extras-1.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=
DISTNAME=

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	http://www.k1.com.br/
COMMENT=	some utilities from FreeBSD

WRKSRC=		${WRKDIR}/${PKGNAME}

INSTALLATION_DIRS=	bin \
			man/man8 \
			man/man1 \
			pkgtools \
			etc/glade/wifimgr \
			etc/sudoers.d \
			share/examples/wifimgr \
			share/examples/netbsd-extras/etc

RCD_SCRIPTS=	runbatch

USE_LANGUAGES+=		python
USE_LANGUAGES+=		c

REPLACE_PYTHON+=        wifimgr *.py

DEPENDS+=	py27-lztlib:../../lzt/py-lztlib
DEPENDS+=	py27-sysctl:../../devel/py-sysctl
DEPENDS+=	sudo:../../security/sudo
DEPENDS+=	netcat:../../net/netcat
DEPENDS+=	rsync:../../net/rsync
DEPENDS+=	cups:../../print/cups


do-extract:
	mkdir -p ${WRKSRC}
	cd ${FILESDIR};rsync --exclude CVS/  -avzHx --delete  src/ pkgtools ${WRKSRC}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit

dorsync:
	cd ..;sh dorsyncpackages netbsd-extras
