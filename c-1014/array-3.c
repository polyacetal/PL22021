#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int *a;

	printf("配列のサイズ > ");
	scanf("%d", &n);

	a = (int *)malloc(sizeof(int)*n);
	if (a == NULL) return(1);

	int a[n];

	a[0] = 123;

	free(a);

	return(0);
}
