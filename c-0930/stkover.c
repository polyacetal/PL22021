#include <stdio.h>

void func(void)
{
	int a[65536];
	printf("%p\n", a);
	func();
}

int main(void)
{
	func();

		return(0);
}
