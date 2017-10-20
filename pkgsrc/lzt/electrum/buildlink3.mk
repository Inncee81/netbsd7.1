# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include	"../../security/py-slowaes/buildlink3.mk"
.include	"../../security/py-ecdsa/buildlink3.mk"
.include	"../../security/py-tlslite/buildlink3.mk"
.include	"../../security/py-pbkdf2/buildlink3.mk"
.include	"../../security/py-protobuf/buildlink3.mk"
.include	"../../devel/py-requests/buildlink3.mk"
.include	"../../devel/py-google-apputils/buildlink3.mk"
.include	"../../net/py-dns/buildlink3.mk"
.include	"../../x11/py-qt4/buildlink3.mk"
.include	"../../graphics/py-qrcode/buildlink3.mk"
