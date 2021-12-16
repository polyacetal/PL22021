#複数プログラムの Makefile
#ver.1 とにかくコンパイルを自動化\
\
seq:\
	gcc seq.c -o seq\
\
sum:\
	gcc sum.c -o sum\



#ver.2 必要な作業だけを自動判断してコンパイル\
\
all: seq sum #make all で連鎖的に seq と sum を make するよ\
\
seq: seq.c\
	gcc seq.c -o seq\
\
sum: sum.c\
	gcc sum.c -o sum\
\
.PHONY: all\



#ver.3 コンパイル以外の作業も自動化

all: seq sum

seq: seq.c
	gcc seq.c -o seq

sum: sum.c
	gcc sum.c -o sum

clean:
	-rm sum seq

dist: clean
	(cd ..; tar zcvf proj-1.tgz proj-1/ )

.PHONY: all clean dist
