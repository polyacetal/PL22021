#include <ncurses.h>

int main(void)
{
	initscr();

	move(10,20);
	addstr("Hello World");
	getch();

	endwin();
	return(0);
}
