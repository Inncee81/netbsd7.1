PKGNAME=	dia-sheets-1.1
CATEGORIES=	lzt
MASTER_SITES:=
.for I in central_data_processing chemistry_lab cmos digital edpc Racks renewable_energy scenegraph
MASTER_SITES+=	http://dia-installer.de/shapes/${I}/
.endfor

EXTRACT_SUFX=	.zip

MAINTAINER=	nervoso@k1.com.br
COMMENT=	more dia sheets

DIST_SUBDIR=	DIA_SHEETS

DISTFILES=      central_data_processing.zip \
                chemistry_lab.zip \
		cmos.zip \
		digital.zip \
		edpc.zip \
		electronic.zip \
		lst.zip \
		optics.zip \
		Racks.zip \
		renewable_energy.zip \
		scenegraph.zip
#post-install:
#	mkdir -p ${DESTDIR}${PREFIX}/etc
#	install -c ${WRKSRC}/.trafshow ${DESTDIR}${PREFIX}/etc/trafshow.sample

.include "../../mk/bsd.pkg.mk"
