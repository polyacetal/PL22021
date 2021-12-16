#Makefile
#ver.1 とにかく分割コンパイルを自動化\
\
all: sumseq\
\
sumseq: main.o sub.o\
	gcc main.o sub.o -o sumseq\
\
main.o: main.c sub.h\
	gcc -c main.c -Wall -DDEBUG\
\
sub.o: sub.c sub.h\
	gcc -c sub.c -Wall -DDEBUG\
\
clean:\
	-rm *.o\
\
distclean: clean\
	-rm sumseq\
\
dist: distclean\
	(cd ..;tar zcvf proj-2.tgz proj-2/)\
\
.PHONY: all clean distclean dist\



#ver.2 変数を利用して記述の効率化\
\
#CFLAGS = -DDEBUG -Wall #コンパイルオプションを変数化\
CFLAGS = -Wall #(デバッグ完了後はこちらを有効化)\
\
all: sumseq\
\
sumseq: main.o sub.o\
	gcc main.o sub.o -o sumseq\
\
main.o: main.c sub.h\
	gcc -c main.c $(CFLAGS)\
\
sub.o: sub.c sub.h\
	gcc -c sub.c $(CFLAGS)\
\
clean:\
	-rm *.o\
\
distclean: clean\
	-rm sumseq\
\
dist: distclean\
	(cd ..;tar zcvf proj-2.tgz proj-2/)\
\
.PHONY: all clean distclean dist\



#ver.3 さらに効率化

#CFLAGS = -DDEBUG -Wall
CFLAGS = -Wall

all: sumseq

sumseq: main.o sub.o
	gcc main.o sub.o -o sumseq

main.o: main.c sub.h

sub.o: sub.c sub.h

.c.o:
	gcc -c $< $(CFLAGS)

.SUFFIXES: .c .o

clean:
	-rm *.o

distclean: clean
	-rm sumseq

dist: distclean
	(cd ..;tar zcvf proj-2.tgz proj-2/)

.PHONY: all clean distclean dist
