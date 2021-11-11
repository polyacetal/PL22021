#include <ncurses.h>
#include <string.h>		// strlen()
#include <unistd.h>

/*
ペンをキー入力でコントロールする．
pen：ペンの状態（参照渡し）
x, y：ペンの位置（参照渡し）
w, h：画面サイズ
key：入力キー
*/
void Ctrl(int *pen, int *x, int *y, int w, int h, int key)
{
	switch (key) {
	case '-': *pen = 0; break;		// on
	case '+': *pen = 1; break;		// off
	case ' ': *pen = (*pen + 1)%2; break;	// on/off切替

	case 'h': (*x)--; if (*x < 0) *x = 0; break;		// ←
	case 'j': (*y)++; if (*y >= h) *y = h - 1; break;	// ↓
	case 'k': (*y)--; if (*y < 0) *y = 0; break;		// ↑
	case 'l': (*x)++; if (*x >= w) *x = w - 1; break;	// →
	}
}

/*
メッセージを画面中央に表示し，キー入力を待つ．
msg：メッセージ文字列
w, h：画面サイズ
return：入力キー
*/
int Info(char *msg, int w, int h)
{
	mvaddstr(h/2, (w - strlen(msg))/2, msg);
	refresh();
	return (getch());
}

/*
ゲーム本体
fin:操作入力用ファイルポインタ
fout:操作記録用ファイルポインタ
*/
void Game(FILE *fin,FILE *fout)
{
	int	pen;	// ペンの状態（0:off，1:on）が入るよ
	int	x, y;	// ペンの位置が入るよ
	int	w, h;	// 画面のサイズが入るよ
	int	key;	// 入力キーの文字が入るよ

	// 初期設定
	erase();			// 画面をクリア
	getmaxyx(stdscr, h, w);		// 画面サイズを取得
	pen = 0; x = w/2; y = h/2;	// ペンの状態・位置を初期化

	while (1) {
		// 描画
//		erase();		// 画面を消去しなければ軌跡が残るよ
		if (pen) mvaddch(y, x, '#');	// ペンのキャラクタを描画
		refresh();		// 画面を表示

		// 入力
		if (fin != NULL) {
			key = fgetc(fin);//ファイルからキーを入力
			usleep(100000);	//100ms停止(再生速度の調整)
		} else {
		key = getch();		// 端末からキーを入力
		}
		if (key == EOF) break;//EOFで終了

		// ペンの操作
		Ctrl(&pen, &x, &y, w, h, key);

		//操作の記録
		if (fout != NULL) fputc(key,fout);

		if (key == 'q') break;	// [Q]で終了
	}
	Info("Done. Hit any key!", w, h);	// 終了確認
}

/*
タイトル画面を表示し，キー入力を待つ．
return：入力キー
*/
int Title(void)
{
	erase();
	mvaddstr( 1, 3, "PenDraw");
	mvaddstr( 3, 3, "Key:");
	mvaddstr( 4, 3, "  [ ][+][-] - pen on/off");
	mvaddstr( 5, 3, "  [H][J][K][L] - move");
	mvaddstr( 6, 3, "  [Q] - quit");
	mvaddstr( 8, 3, "Imput from:");
	mvaddstr( 9, 3, "  [K] - keyboard");
	mvaddstr(10, 3, "  [F] - file (key sequence 'key.txt')");
	mvaddstr(11, 3, "  [P] - pipe (PDCL script 'script.txt')");
	refresh();
	return (getch());
}

int main(void)
{
	FILE *fin;
	FILE *fout;
	int	key;	// 入力キーの文字が入るよ

	// 初期設定
	initscr();	// 端末制御を開始
	noecho();	// 入力キーは表示するなよ
	cbreak();	// 入力バッファは使うなよ
	curs_set(0);	// カーソルは表示するなよ
	timeout(-1);	// キー入力は来るまで待てよ

	// メインループ
	while (1) {
		key = Title();		// タイトル
		if (key == 'q') break;

		//ファイルの準備
		switch (key) {
			case 'f':	//自動操作(ファイル入力)
				fin = fopen("key.txt", "r");
				fout = NULL;
				break;
			case 'p':	//自動操作(パイプ入力)
				fin = popen("./pdcl script.txt", "r");
					//pdclの出力シーケンスを入力するよ
				fout = NULL;
				break;
			default:	//手動操作(キー入力,ファイル記録)
				fin = NULL;
				fout = fopen("key.txt", "w");
				break;
		}
		Game(fin, fout);			// ゲーム本体(引数の再追加)

		//操作記録用ファイルの後始末
		if (fin != NULL) {
			if (key == 'p') {
				pclose(fin);		//パイプの後始末
			} else {
				fclose(fin);		//ファイルの後始末
			}
		}
		if (fout != NULL) fclose(fout);
	}

	// 終了
	endwin();	// 端末制御を終了
	return (0);
}

