/* Tic-Tac-Toe 超簡易版 */
// ver.6 フルスクリーン化
/*
 * 主な変更点:
 * 	main()の一部をGame()に移動
 * 	Title()の表示内容
 * 	入出力処理をcurses化
 */

#include <locale.h>
#include <ncurses.h>
#include <stdlib.h>

typedef struct {
	int	size;
	int	*cell;
} Board;

//ゲーム盤などの表示開始位置
#define Y0 3
#define X0 3

//駒の表示記号(グローバル変数)
char *sym[3] = {"・","○","☓"};	//空欄,プレイヤー1,プレイヤー2

/* タイトルを表示する関数 */
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

/* 以下のゲーム盤関連の関数群に共通する変数
 * bd：ゲーム盤の静的２次元配列
 * y, x：ゲーム盤のマスの行番号，列番号
 * v：プレーヤ番号
 */
void FreeBoard(Board *bd)
{
	if (bd == NULL) return;
	free(bd->cell);
	free(bd);
}

Board *NewBoard(int n)
{
	Board	*bd;

	bd = (Board *)malloc(sizeof(Board));
	if (bd == NULL) return (NULL);

	bd->size = n;
	bd->cell = (int *)malloc(sizeof(int)*n*n);
	if (bd->cell == NULL) {
		free(bd);
		return (NULL);
	}
	return (bd);
}

/* ゲーム盤のプレーヤ番号を調べる関数
 * return：プレーヤ番号
 */
int Get(Board *bd, int y, int x)
{
	if (x < 0) return (-1);		/* ハミ出し禁止 */
	if (x >= bd->size) return (-1);	/* （バッファオーバラン防止） */
	if (y < 0) return (-1);
	if (y >= bd->size) return (-1);

	return (bd->cell[y*bd->size + x]);
}

/* ゲーム盤にプレーヤ番号を書き込む関数 */
void Set(Board *bd, int y, int x, int v)
{
	if (x < 0) return;		/* ハミ出し禁止 */
	if (x >= bd->size) return;	/* （バッファ−バラン防止） */
	if (y < 0) return;
	if (y >= bd->size) return;

	bd->cell[y*bd->size + x] = v;
}

/* ゲーム盤を初期化する関数 */
void Clear(Board *bd)
{
	int	y, x;

	for (y = 0; y < bd->size; y++) {
		for (x = 0; x < bd->size; x++) {
			bd->cell[y*bd->size + x] = 0;
		}
	}
}

/* ゲーム盤を表示する関数 */
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
	bd = NewBoard(n);
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

	FreeBoard(bd);
	return (0);

ERROR:
	printw("メモリ確保失敗\n");
	return (1);
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

