#include <stdio.h>
#include <stdlib.h>	// atoi()
#include <string.h>	// strtok()

#define BUFLEN	256	// バッファ文字列のサイズ
#define ARGS	16	// コマンド引数の個数の最大値

int proc(FILE *fp)
{
	int	key;		// 出力キーの文字
	char	line[BUFLEN];	// 入力行（コマンドライン）文字列のバッファ
	int	argc;		// コマンド引数の個数
	char	*argv[ARGS];	// コマンド引数の配列
	char	*cmd;		// コマンド名（argv[0] のコピー）
	char	*tok, *p;	// strtok()の作業用ポインタ
	int	n;		// コマンドの反復回数
	int	i;		// カウンタ
	long int pos;

	while (1) {
		// スクリプトの入力
		if (fgets(line, BUFLEN, fp) == NULL) break;

		// スクリプトのトークン分解
		p = line;	// strtok()の１回目は入力行の先頭を対象とする
		for (i = 0; i < ARGS; i++) {
			tok = strtok(p, " \t\n");
			// 空白，タブ，改行を区切としてトークンを抽出
			// 注意：lineの内容が改変される．区切文字 → 終端記号
			p = NULL;
				// ２回目以降は入力行内の残りの部分を対象とする

			if (tok == NULL) break;
			if (tok[0] == '#') break;	// コメントを無視
			argv[i] = tok;
		}
		if (i == 0) continue;
		argc = i;
		cmd = argv[0];

		// スクリプトの解釈
		// 制御構造コマンド repeat-end
		if (strcmp(cmd, "repeat") == 0) {
			if (argc < 2) {
				n = 1;
			} else {
				n = atoi(argv[1]);
			}

			pos = ftell(fp);
			for (i = 0; i < n; i++) {
				if(fseek(fp, pos, SEEK_SET)) goto ERROR;
					//ファイルを巻き戻す(repeat直後へ)
				if (proc(fp)) goto ERROR;
					//repeat-end間を再帰処理(n回反復)
			}
			//...n <= 0 だとバグるのは仕様です
			continue;
		} else
		if (strcmp(cmd, "end") == 0) return (0);
			//再帰終了(for内へ戻る)

		// ペン状態切替コマンド
		if (strcmp(cmd, "off") == 0) key='-';
		else if (strcmp(cmd, "on") == 0) key='+';

		// ペン移動コマンド
		else if (strcmp(cmd, "up") == 0) key='k';
		else if (strcmp(cmd, "down") == 0) key='j';
		else if (strcmp(cmd, "left") == 0) key='h';
		else if (strcmp(cmd, "right") == 0) key='l';

		// その他...シンタックスエラー
		else continue;		// とりあえず無視しておく

		// pendraw操作用キーシーケンスの出力
		if (argc < 2) {		// 引数なしの場合
			n = 1;			// １回だけ
		} else {		// ありの場合
			n = atoi(argv[1]);	// 反復回数
		}
		for (i = 0; i < n; i++) {
			fputc(key, stdout);
		}
	}
ERROR:		//エラー処理は未実装
	return (EOF);
}

int main(int argc, char *argv[])
{
	FILE	*fp;
	int	i;

	for (i = 1; i < argc; i++) {
		fp = fopen(argv[i], "r");
		if (fp == NULL) break;
		proc(fp);
		fclose(fp);
	}
	fputc('q', stdout);
	return (EXIT_SUCCESS);
}

