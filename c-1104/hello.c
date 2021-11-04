#include <ncurses.h>

int main(void)
{
	initscr();

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLUE);
	bkgd(COLOR_PAIR(1));

	erase();
	move(10,20);
	addstr("Hello World");
	refresh();

	timeout(-1);
	getch();

	endwin();
	return(0);
}
