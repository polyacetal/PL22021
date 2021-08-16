#include <stdio.h>
#include <string.h>

#define BUFLEN 256
#define BUFFMT "%255s"

int sum(char *file)
{
	FILE *fp = NULL;
	int t = 0;
	int x;

	fp = fopen(file, "r");
	if (fp == NULL) {
		perror("オープン失敗");
		return (0);
	}
	while (fscanf(fp, "%d", &x) != EOF) {
		t += x;
	}
	printf("小計:%d\n", t);
	if (fp != NULL) fclose(fp);
	return (t);
}

void help()
{
	char cmd[BUFLEN];
	char *fmt = BUFFMT;
	printf("exit\n");
	printf("help\n");
	printf("reset\n");
	printf("show\n");
	printf("sum ファイル名\n");
	printf("save ファイル名\n");
	printf("helpはexitで抜けられます.このプログラムの停止もexitで行えます.\n");
	printf("コマンドを入力すると詳しいhelpが見れます.\n");
	while(1) {
		printf("\nhelp > ");
		if(scanf(fmt, cmd) == EOF) break;
		if(strcmp(cmd, "exit") == 0) break;
		else if (strcmp(cmd, "help") == 0) {
			printf("helpです.\n");
		}
		else if (strcmp(cmd, "reset") == 0) {
			printf("合計を0に戻します.\n");
		}
		else if (strcmp(cmd, "show") == 0) {
			printf("これまで合計を表示させます.\n");
		}
		else if (strcmp(cmd, "sum") == 0) {
			printf("sum ファイル名　でファイルの中の値の総和を出します.\n");
		}
		else if (strcmp(cmd, "save") == 0) {
			printf("save ファイル名　でファイルに合計の値を出力します.\n");
		}
		else {printf("エラー:不明なコマンド:%s\n", cmd);}
	}
}

void save(char *file, int total)
{
	FILE *fp = NULL;

	fp = fopen(file, "w");
	if (fp == NULL){
		perror("オープン失敗");}
	fprintf(fp, "%d\n", total);
	fclose(fp);
}

int main(void)
{
	int total = 0;
	char cmd[BUFLEN];
	char arg[BUFLEN];

	char *fmt = BUFFMT;
/*
	char fmt[16];
	sprintf(fmt, "%%ds", BUFLEN-1);
*/
	while(1) {
		printf("命令 > ");
		if(scanf(fmt, cmd) == EOF) break;
		if(strcmp(cmd, "exit") == 0) break;
		else if (strcmp(cmd, "sum") == 0) {
			scanf(fmt, arg);
			total += sum(arg);
		}
		else if (strcmp(cmd, "show") == 0) {
			printf("合計:%d\n", total);
		}
		else if (strcmp(cmd, "reset") == 0) {
			total = 0;
		}
		else if (strcmp(cmd, "save") == 0) {
			scanf(fmt, arg);
			save(arg, total);
		}
		else if (strcmp(cmd, "help") == 0) {
			help();
		}
		else {printf("エラー:不明なコマンド:%s\n", cmd);}
		printf("\n");
	}
	printf("終了. \n\n");
	return(0);
}
