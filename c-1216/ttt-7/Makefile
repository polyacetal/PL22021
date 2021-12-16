all: ttt-7

ttt-7: main.o game.o board.o
	gcc main.o game.o board.o -lncursesw -ltinfo -o ttt-7

main.o:

game.o:

board.o:

.c.o:
	gcc -c $< 

.SUFFIXES: .c .o

.PHONY: all clean distclean dist
