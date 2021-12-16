#include <ncurses.h>
#include "board.h"
#include "game.h"

char *sym[3] = {"・","○","☓"};	//空欄,プレイヤー1,プレイヤー2

void Draw(Board *bd)
{
	int	y, x;

	printf("\n");
	for (y = 0; y < bd->size; y++) {
		for (x = 0; x < bd->size; x++) {
			printf("%2d", bd->cell[y*bd->size + x]);
			mvprintw(y + Y0, 2*x + X0, "%s", sym[Get(bd, y, x)]);
		}
	}
	printf("\n\n");
}

int Game(void)
{
	Board *bd;
	int n;
	int y, x, player;

	erase();
	mvprintw(Y0, X0, "ゲーム盤のサイズ > ");
	refresh();
	if (scanw("%d", &n) == ERR) return (0);
		//数値入力なしだとERRになるよ
	bd = New(n);
	if (bd == NULL) return (1);

	Clear(bd);

	player = 1;
	while (1) {
	CONTINUE:
		erase();
		Draw(bd);
		refresh();

		while (1) {
			printw("%s の番 > ", sym[player]);
			refresh();
			if(scanw("%d %d", &y, &x) == ERR) goto END;

			if (Get(bd, y, x) == 0) break;
			printw("そこには置けません!!\nもう一度");
		}
		Set(bd, y, x, player);

		player = player%2 + 1;
	}
END:
	printw("中止？ (y/n)");
	if (getch() != 'y') goto CONTINUE;

	Free(bd);
	return (0);

ERROR:
	printw("メモリ確保失敗\n");
	return (1);
}
