#!/bin/sh
set -e
PKG=${1:-NONE}
if pkg_info -qe ${PKG}
then
	PKGPATH=$(pkg_info -Q PKGPATH  ${PKG})
else
	PKGPATH=$1
fi
if [ -d $(basename ${PKGPATH}) ]
then
	echo $PKGPATH ja existe
	exit 1
fi
rsync --exclude CVS -avzHx /usr/pkgsrc/$PKGPATH /usr/pkgsrc/lzt
