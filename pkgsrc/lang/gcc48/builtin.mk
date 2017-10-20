BUILTIN_PKG:=	gcc48

.include "../../mk/buildlink3/bsd.builtin.mk"

GCCTESTE!=		gcc -v 2>&1 | grep "gcc version" | awk '{print $$3}'

.if !empty(GCCTESTE:M4.8.*)
IS_BUILTIN.gcc48=	yes
.else
IS_BUILTIN.gcc48=	no
.endif

MAKEVARS+=      IS_BUILTIN.gcc48
MAKEVARS+=      USE_BUILTIN.gcc48
