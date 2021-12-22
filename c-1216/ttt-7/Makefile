all: ttt-7

ttt-7: main.o game.o board.o
	gcc main.o game.o board.o -lncursesw -ltinfo -o ttt-7

main.o: main.c game.h

game.o: game.c game.h board.h

board.o: board.c board.h

.c.o:
	gcc -c $< 

clean:
	-rm *.o

distclean: clean
	-rm ttt-7

dist:distclean
	(cd ..; tar zcvf ttt-7.tgz ttt-7/)
.SUFFIXES: .c .o

.PHONY: all clean distclean dist
