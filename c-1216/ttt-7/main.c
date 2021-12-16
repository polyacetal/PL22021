#include <locale.h>
#include <ncurses.h>
#include "game.h"

int Title(void)
{
	erase();
	mvprintw(Y0+ 0, X0, "+-------------------------------+");
	mvprintw(Y0+ 1, X0, "| The Most Simplest TIC-TAC-TOE |");
	mvprintw(Y0+ 2, X0, "+-------------------------------+");

	mvprintw(Y0+ 4, X0, "  位置の指定は行番号y，列番号x の順ね．");
	mvprintw(Y0+ 5, X0, "    （番号は 0 から数えるよ．）");
	mvprintw(Y0+ 6, X0, "  勝敗については自分達で判定すれや．");

	mvprintw(Y0+ 8, X0, "  プレイヤー1 : %s", sym[1]);
	mvprintw(Y0+ 9, X0, "  プレイヤー2 : %s", sym[2]);

	mvprintw(Y0+ 11, X0, "  終了:ここで[Q] or ゲーム中に[Enter]");
	mvprintw(Y0+ 12, X0, "  開始:[Enter]");
	refresh();
	return (getch());
}

int main(void)
{
	setlocale(LC_ALL, "");
	initscr();

	while (1) {
		if (Title() == 'q') break;

		if (Game()) break;
	}
	endwin();	//端末制御を終了

	return (0);
}

