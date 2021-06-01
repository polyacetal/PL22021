#include <stdio.h>

int main(void)
{
	int x,y;
	int r = 10;
	int n = 3;

	for (y = 0; y < r; y++) {
		for (x = 0; x < r; x++) {
			printf("#");
		}
		printf("\n");
	}

		return(0);
}
