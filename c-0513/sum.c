#include <stdio.h>

int main(void)
{
	int n, i, sum;

	printf("非負整数 n > ");
	scanf("%d", &n);

	sum = 0;

	for (i = 0; i <= n; i++) {
		sum += i;
	}

	printf("総和 Sn = %d\n", sum);

		return(0);
}
