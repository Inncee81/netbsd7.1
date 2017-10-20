all: \
	dorsyncpackages \
	importpkg \
	makepkglinks \
	makepatchfiles

cvs:
	cvs up
	cvs commit

dorsyncall:
	find * -type d -maxdepth 0 \! -name CVS | \
		while read p; do \
		./dorsyncpackages $$p;\
		done
