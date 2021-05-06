#include <stdio.h>

int main(void)
{
		int x = 123;
		double y = 123.45;

		printf("正:\n");
		printf("x =%d\n", x);
		printf("y =%f\n", y);

		printf("誤:\n");
		printf("x =%f\n", x);
		printf("y =%d\n", y);

		return(0);
}
