#include <stdio.h>

#define WC 10
#define NC 11

int main(void)
{
	int x;
	int c;
	int i;
	int f[NC] = {};

	printf("成績を入力してください (0~100,最後に-1)\n");
LOOP:
	while (1) {
		scanf("%d", &x);
		if (x < 0) break;
		if (x > 100) goto ERROR;

		c = x/WC;
		f[c]++;
	}
RESULT:
	printf("階級:度数:グラフ\n");
	for (c = NC - 1; c >= 0; c--) {
		printf("%3d : %3d : ", c*WC, f[c]);
		for (i = 0; i < f[c]; i++) {
			printf("*");
		}
		printf("\n");
	}

	return (0);

ERROR:
	printf("エラー:不正な入力を無視しました.100以内な!!\n");
	goto LOOP;
}
