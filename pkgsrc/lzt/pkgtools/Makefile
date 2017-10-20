.include "../../lang/python/distutils.mk"

all: \
	${LOCALBASE}/${PYSITELIB}/pkgutils.py \
	${HOME}/bin/buildpackage \
	${HOME}/bin/removepackage \
	${HOME}/bin/runbuildpackage 
	rm -f *.pyc

${LOCALBASE}/${PYSITELIB}/pkgutils.py: pkgutils.py
	install -m 755 $> $@

${HOME}/bin/removepackage: removepackage
	install -m 755 $> $@

${HOME}/bin/buildpackage: buildpackage
	install -m 755 $> $@

${HOME}/bin/runbuildpackage: runbuildpackage
	install -m 755 $> $@

.include "../../mk/bsd.pkg.mk"


cvs:
	cvs up
	cvs commit
