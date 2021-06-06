#include <stdio.h>
#define N_DATA 3

int main(void)
{
	int data[N_DATA] = {};
	int i;

	while (1) {
		printf("要素番号 (-1で終了) > ");
		scanf("%d", &i);
		if (i < 0) break;
		if (i >= N_DATA) continue;

		printf("%d番目の整数データ > ", i);
		scanf("%d", &data[i]);

	printf("データ:");
	for (i = 0; i < N_DATA; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");
	}

		return(0);
}
