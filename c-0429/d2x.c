#include <stdio.h>

int main(void)
{
		int value;

		while (1) {
				printf("10進数 >");
				scanf("%d", &value);
				printf("16進数 = %X\n", value);
		}

		return(0);
}
