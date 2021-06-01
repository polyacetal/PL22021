#include <stdio.h>

int main(void)
{
	int x,y;
	int r = 10;
	int n = 3;

	for (y = 0; y < r; y++) {
		if (1 == y%n) continue;
		for (x = 0; x < r; x++) {
			if (x > y) continue;
			printf("#");
		}
		printf("\n");
	}

		return(0);
}
