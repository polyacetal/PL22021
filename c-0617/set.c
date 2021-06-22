#include <stdio.h>

int set(int *p, int n, int i, int v) {
	if (i < 0) return (1);
	if (i >= n) return (1);

	p[i] = v;
	return (0);
}

#define NUM 10

int main(void)
{
	int a[NUM];
	int n = 0;

	n += set(a, NUM, 8, 1);
	// a[8] = 1; n++;
	printf("8: OK\n");

	n += set(a, NUM, -100, 1);
	// a[-100] = 1; n++;
	printf("-100: OK\n");

	n += set(a, NUM, 10000, 1);
	// a[10000] = 1; n++;
	printf("10000: OK\n");

	printf("オーバーラン防止回数:%d\n", n);

		return(0);
}
