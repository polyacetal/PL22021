#include <stdio.h>

int main(void)
{
	int b[2][3] = {
		{ 0, 1, 2},
		{ 3, 4, 5}
	};
	int *c;
	int x,y;

	c = (int *)b;

	for (y = 0; y < 2; y++) {
		for (x = 0; x < 3; x++) {
			printf("d[%d][%d] = %d ,   ", y, x, b[y][x]);
			printf("c[%d*3 + %d] = %d\n", y, x, c[y*3 + x]);
		}
	}


	return(0);
}
