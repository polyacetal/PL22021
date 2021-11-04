#include <stdio.h>

int main(void)
{
	int x = 1;
	int i;

	for (i = 0; i <=64; i++) {
		x = x * 16;
		printf("%X\n", x);
	}

	return(0);
}
