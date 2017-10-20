# $NetBSD$

DISTNAME=	youtube-dl-2017.03.10
CATEGORIES=	net
MASTER_SITES=	https://yt-dl.org/downloads/2017.03.10/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	https://yt-dl.org/downloads/2017.03.10/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/youtube-dl
USE_LANGUAGES=	# none

post-extract:
	${RM} ${WRKSRC}/youtube-dl

.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../net/rtmpdump/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
