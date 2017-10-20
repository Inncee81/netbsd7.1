PROG=	daemon
SRCS=	daemon.c pidfile.c flopen.c
MAN=	daemon.8

BINDIR=	${PREFIX}/bin
MANDIR=	${PREFIX}/man

LDFLAGS+=-L${PREFIX}/lib -lutil

.include <bsd.prog.mk>
