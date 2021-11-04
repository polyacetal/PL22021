#include <stdio.h>

#define SIZE 1000000

int main(void)
{
	int a[SIZE];
	int n;

	printf("配列のサイズ > ");
	scanf("%d", &n);
	if (n >= SIZE) return (1);

	int a[n];

	a[0] = 123;

	return(0);
}
