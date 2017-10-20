#!/bin/sh

eval P=\${$#}
PKGNAME=$(pkg_info -e "$P")

if /usr/sbin/pkg_delete.bin "$@"
then
	if [ -z "${PKGNAME_REQD}" ]
	then
		if ! pkg_info -qe "${PKGNAME}"
		then
			. /usr/pkg/pkgtools/profile
			/usr/pkg/pkgtools/pkglztadmin del "${PKGNAME}"
		fi
	fi
fi
