.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.if ! emtpty(RCD_SCRIPTS)
INSTALLATION_DIRS+=share/examples/rc.d
RCDIR=	${PREFIX}/share/examples/rc.d

.for R in ${RCD_SCRIPTS}
CONF_FILES_PERMS+=${RCDIR}/${R} /etc/rc.d/${R} \
	${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755
.endfor
.endif
