#include <stdio.h>

int power(int x, int y) {
	int i;
	if (y == 0) {
		return (1);
	} else {
		i = power(x,y-1) * x;
		return(i);
	}
}
int main(void)
{
	int x,y;

	printf("x,y > ");
	scanf("%d %d", &x, &y);

	printf("%d^%d = %d\n", x, y, power(x,y));

		return(0);
}
