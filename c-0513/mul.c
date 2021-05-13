#include <stdio.h>

int main(void)
{
	int x,y,z;
	int i;

	printf("非負整数 x, y > ");
	scanf("%d %d", &x, &y);

	z = 0;

	for (i = 0; i < y; i++) {
		z += x;
	}

	printf("%d * %d = %d\n", x, y, z);

		return(0);
}
