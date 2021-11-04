#include <ncurses.h>
#include <string.h>

int main(void)
{
	int x, y, w, h;
	char *str = "Hello World";
	int key;

	initscr();
	noecho();
	cbreak();
	getmaxyx(stdscr, h, w);
	y = h/2;
	x = (w - strlen(str))/2;

	while (1) {
		erase();
		move(y,x);
		addstr(str);
		refresh();

		key = getch();
		if (key == 'q') break;
		y++; if (y >= h) y = 0;
	}
	endwin();
	return(0);
}
