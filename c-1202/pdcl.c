#include <stdio.h>
#include <stdlib.h>	// atoi()
#include <string.h>	// strtok()

#define BUFLEN	256	// バッファ文字列のサイズ
#define ARGS	16	// コマンド引数の個数の最大値
#define IfStr(s1, op, s2) if (strcmp(s1, s2) op 0)

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
		IfStr(cmd, ==, "repeat") {
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
		IfStr(cmd, ==, "end") return (0);
			//再帰終了(for内へ戻る)

		// ペン状態切替コマンド
		IfStr(cmd, ==, "off") key ='-';
		else IfStr(cmd, ==, "on") key ='+';
		else IfStr(cmd, ==, "erase") key ='x';

		// ペン移動コマンド
		else IfStr(cmd, ==, "up") key='k';
		else IfStr(cmd, ==, "down") key='j';
		else IfStr(cmd, ==, "left") key='h';
		else IfStr(cmd, ==, "right") key='l';

		//リセットコマンド
		else IfStr(cmd, ==, "reset") key='!';
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

