#include <ncurses.h>

int main(void)
{
	initscr();

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLUE);
	init_pair(2, COLOR_GREEN, COLOR_BLUE);
	init_pair(3, COLOR_YELLOW, COLOR_BLUE);
	init_pair(10, COLOR_WHITE, COLOR_BLUE);
	bkgd(COLOR_PAIR(10));

	attrset(COLOR_PAIR(1));
	mvaddstr(5,  5, "Hello World");
	attrset(COLOR_PAIR(2));
	mvaddstr(5, 25, "Hello World");
	attrset(COLOR_PAIR(3));
	mvaddstr(5, 45, "Hello World");

	attrset(COLOR_PAIR(1) | A_BOLD);
	mvaddstr(6,  5, "Hello World");
	attrset(COLOR_PAIR(2) | A_BOLD);
	mvaddstr(6, 25, "Hello World");
	attrset(COLOR_PAIR(3) | A_BOLD);
	mvaddstr(6, 45, "Hello World");

	attrset(COLOR_PAIR(1) | A_REVERSE);
	mvaddstr(7,  5, "Hello World");
	attrset(COLOR_PAIR(2) | A_REVERSE);
	mvaddstr(7, 25, "Hello World");
	attrset(COLOR_PAIR(3) | A_REVERSE);
	mvaddstr(7, 45, "Hello World");

	attrset(COLOR_PAIR(1) | A_REVERSE | A_BOLD);
	mvaddstr(8,  5, "Hello World");
	attrset(COLOR_PAIR(2) | A_REVERSE | A_BOLD);
	mvaddstr(8, 25, "Hello World");
	attrset(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
	mvaddstr(8, 45, "Hello World");

	getch();
	endwin();
	return(0);
}
