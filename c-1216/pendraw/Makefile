all: pendraw pdcl

pendraw: pendraw.c
	gcc pendraw.c -lncurses -o pendraw

pdcl: pdcl.c
	gcc pdcl.c -o pdcl

distclean: clean
	-rm pendraw pdcl

dist:distclean
	(cd ..; tar zcvf pendraw.tgz pendraw/)

.PHONY: all clean distclean dist
