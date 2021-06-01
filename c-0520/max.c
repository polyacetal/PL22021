#include <stdio.h>

int main(void)
{
	int x;
	int max = 0;

	while (1) {
		printf("得点 > ");
		scanf("%d", &x);

		if (x < 0) break;
		if (x > max) max = x;
	}

	printf("最大値 = %d\n", max);

		return(0);
}
