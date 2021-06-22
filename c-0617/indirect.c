#include <stdio.h>

int main(void)
{
	int x = 1;
	int y = 2;
	int *p;

	printf("&x = %p, x = %d\n", &x, x);
	printf("&y = %p, y = %d\n", &y, y);
	printf("\n");

	p = &x;
	printf("p = %p, *p = %d\n", p, *p);
	*p = 128;
	printf("p = %p, *p = %d\n", p, *p);

	printf("&x = %p, x = %d\n", &x, x);
	printf("&y = %p, y = %d\n", &y, y);
	printf("\n");

	p = &y;
	printf("p = %p, *p = %d\n", p, *p);
	*p = 256;
	printf("p = %p, *p = %d\n", p, *p);

	printf("&x = %p, x = %d\n", &x, x);
	printf("&y = %p, y = %d\n", &y, y);
	printf("\n");

		return(0);
}
