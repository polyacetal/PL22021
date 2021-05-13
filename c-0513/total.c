#include <stdio.h>

int main(void)
{
	int total;
	int x;

	/*
	int n,i;

	printf("データの個数 > ");
	scanf("%d", &n);

	total = 0;
	printf("%d 個の非負整数 > ", n);

	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		total += x;
	}
*/

	/*
	total = 0;
	printf("複数個の非負整数 (最後に -1) > ");
	x = 0;

	while (x >= 0) {
		scanf("%d", &x);
		total += x;
	}
	total -= x;
	*/

	total = 0;
	printf("複数個の非負整数 (最後に -1) > ");
	x = 0;
	do {
		total += x;
		scanf("%d", &x);
	} while (x >= 0);

	printf("合計 = %d\n", total);

	return(0);
}
