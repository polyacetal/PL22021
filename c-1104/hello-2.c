#include <ncurses.h>
#include <string.h>

int main(void)
{
	int x, y, w, h;
	char *str = "Hello World";

	initscr();
	getmaxyx(stdscr, h, w);
	y = h/2;
	x = (w - strlen(str))/2;

	move(y,x);
	addstr(str);
	getch();

	endwin();
	return(0);
}
