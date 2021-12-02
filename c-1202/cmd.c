#include <stdio.h>
#include <string.h>

#define DEBUG		//フラグマクロの定義...デバッグモードon
 #undef DEBUG	//マクロ定義を解除...デバッグモードoff

#define BUFLEN 256

//関数のようなマクロ:文字列比較の条件式の定義
#define StrEql(s1, s2) (strcmp(s1, s2) == 0)

//制御構造のようなマクロ1:文字列比較専用のif文の定義
#define IfStr(s1, op, s2) if (strcmp(s1, s2) op 0)

//制御構造のようなマクロ2:cmd比較専用のif文の定義
#define IfCmdIs(s) if (strcmp(cmd, s) == 0)
int main(void)
{
	char buf[BUFLEN];
	char *cmd;
	FILE *fp = stdin;

	while (1) {
		printf("コマンド > ");
		fgets(buf,BUFLEN, fp);
		cmd = strtok(buf, " \t\n");
#ifdef DEBUG	//ここから...デバッグ用コード
		printf("cmd:[%s]\n", cmd);	//デバッグ用のコード
						//変数(入力文字列)を表示してみる, i.e.printfデバッグ
#endif			//...ここまで
		if (StrEql(cmd, "quit")) break;	//意図を明確化
//	IfStr(cmd, ==, "quit") break;		//意図を更に明確化
//	IfCmdIs("quit") break;					//コードを短縮
	}

	return(0);
}
