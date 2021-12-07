/* Tic-Tac-Toe 超簡易版 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int size;		//ゲーム盤のサイズ(旧変数名:n)
	int *cell;	//マスの動的配列へのポインタ(旧変数名:bd)
} Board;

/* タイトルを表示する関数 */
void Title()
{
	printf("+-------------------------------+\n");
	printf("| The Most Simplest TIC-TAC-TOE |\n");
	printf("+-------------------------------+\n");
	printf("\n");
	printf("  位置の指定は行番号y，列番号x の順ね．\n");
	printf("    （番号は 0 から数えるよ．）\n");
	printf("  勝敗については自分達で判定すれや．\n");
	printf("  終了するには [Ctrl]+[D]．\n");
	printf("\n");
}

/* 以下のゲーム盤関連の関数群に共通する変数
 * bd：ゲーム盤の動的1次元配列
 * y, x：ゲーム盤のマスの行番号，列番号
 * v：プレーヤ番号
 */

/* ゲーム盤のプレーヤ番号を調べる関数
 * return：プレーヤ番号
 */
int Get(Board bd, int y, int x)
{
	if (x < 0) return (-1);		/* ハミ出し禁止 */
	if (x >= bd.size) return (-1);	/* （バッファオーバラン防止） */
	if (y < 0) return (-1);
	if (y >= bd.size) return (-1);

	return (bd.cell[y*bd.size+x]);
}

/* ゲーム盤にプレーヤ番号を書き込む関数 */
void Set(Board bd, int y, int x, int v)
{
	if (x < 0) return;		/* ハミ出し禁止 */
	if (x >= bd.size) return;		/* （バッファ−バラン防止） */
	if (y < 0) return;
	if (y >= bd.size) return;

	bd.cell[y*bd.size+x] = v;
}

/* ゲーム盤を初期化する関数 */
void Clear(Board bd)
{
	int i;

	for (i = 0; i < bd.size*bd.size; i++) {
		bd.cell[i] = 0;
	}
}

/* ゲーム盤を表示する関数 */
void Draw(Board bd)
{
	int	y, x;

	printf("\n");
	for (y = 0; y < bd.size; y++) {
		for (x = 0; x < bd.size; x++) {
			printf("%2d", bd.cell[y*bd.size+x]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
	Board bd;
	int n;
		/* ゲーム盤の動的1次元配列
		 * 各マスのコマのプレーヤ番号（1 or 2）を記録するよ
		 * 空白のマスはゼロね
		 */
	int	y, x, player;
		/* 行番号，列番号，プレーヤ番号（1 or 2） */

	Title();

	printf("ゲーム盤のサイズ > ");
	scanf("%d", &n);

	bd.size = n;
	bd.cell =(int *)malloc(sizeof(int)*n*n);
	if (bd.cell == NULL) return (1);

	Clear(bd);

	player = 1;
	while (1) {
		Draw(bd);

		while (1) {
			printf("%dP の番 > ", player);
			if (scanf("%d %d", &y, &x) == EOF) goto END;

			if (Get(bd, y, x) == 0) break;
			printf("そこには置けません!!\nもう一度 ");
		}
		Set(bd, y, x, player);

		player = player%2 + 1;		/* 1→ 2，2→ 1 */
	}
END:
	printf("\n終了\n");
	free(bd.cell);
	return (0);
}

