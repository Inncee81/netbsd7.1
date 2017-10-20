# $NetBSD$

PKGNAME=	sqlcipher-3.2.0
DISTNAME=	sqlcipher-sqlcipher-v3.2.0_GH0
CATEGORIES=	lzt
MASTER_SITES=	https://codeload.github.com/sqlcipher/sqlcipher/tar.gz/v3.2.0?dummy=/

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	https://codeload.github.com/sqlcipher/sqlcipher/tar.gz/v3.2.0?dummy=/
COMMENT=	secure sqlite database
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/sqlcipher-3.2.0
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	sqlcipher.pc.in
PKGCONFIG_OVERRIDE+=	sqlite.pc.in
GNU_CONFIGURE=  yes

CONFIGURE_ARGS+=--enable-tempstore=yes --disable-tcl --enable-readline
CPPFLAGS+=      -DSQLITE_HAS_CODEC

.include	"../../lang/tcl/buildlink3.mk"
.include	"../../devel/readline/buildlink3.mk"
.include	"../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

cvs:
	cvs up
	cvs commit
