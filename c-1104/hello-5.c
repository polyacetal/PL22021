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
	keypad(stdscr, TRUE);
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
		switch (key) {
			case KEY_UP:    y--; break;
			case KEY_DOWN:  y++; break;
			case KEY_LEFT:  x--; break;
			case KEY_RIGHT: x++; break;
		}
	}
	endwin();
	return(0);
}
