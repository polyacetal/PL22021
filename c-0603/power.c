#include <stdio.h>

int power(int x, int y)
{
	int i;
	int z = 1;

	for (i = 0; i < y; i++) {
		z *=x;
	}
	return (z);
}
int main(void)
{
	int x,y,z;

	printf("x,y > ");
	scanf("%d %d", &x, &y);

	z = power(x, y);

	printf("%d^%d = %d\n", x, y, z);

		return(0);
}
