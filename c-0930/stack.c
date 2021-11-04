#include <stdio.h>

void sub1(void)
{
	int x;
	printf("%p : x@sub1\n", &x);
}

void sub2(void)
{
	int y;
	sub1();
	printf("%p : y@sub2\n", &y);
}

void sub3(void)
{
	int z;
	sub2();
	printf("%p : z@sub3\n", &z);
}

int main(void)
{
	sub1();
	printf("-----\n");
	sub2();
	printf("-----\n");
	sub3();

		return(0);
}
