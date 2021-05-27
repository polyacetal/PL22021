#include <stdio.h>

int main(void)
{
	int total = 0;
	int x;
	int n = 0;
	double avg;

	n = 0;
LOOP:
	while (1) {
		printf("%d番目の非負整数(-1で終了) >", n);
		scanf("%d", &x);
		if (x < 0) break;
		if (x > 100) goto ERROR;
			total += x;
			n++;
	}
END:
	avg = (double)total/(double)n;
	printf("平均 = %f\n", avg);

		return(0);
ERROR:
		printf("エラー:範囲外の値\n");
		printf("続けますか？ (0:終了/その他:続行) >");
		scanf("%d", &x);
		if (x == 0) goto END;
		goto LOOP;
}
