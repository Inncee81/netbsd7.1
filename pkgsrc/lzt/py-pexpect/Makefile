# $NetBSD$

PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
DISTNAME=	pexpect-4.2.1
CATEGORIES=	lzt
MASTER_SITES=	https://files.pythonhosted.org/packages/source/p/pexpect/

MAINTAINER=	nervoso@k1.com.br
HOMEPAGE=	https://files.pythonhosted.org/packages/source/p/pexpect/
COMMENT=	Pure python expect like module

post-patch:
	cd ${WRKSRC};rm -f pexpect/async.py

.include "../../lang/python/distutils.mk"
.include "../../lzt/py-ptyprocess/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
