#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n = 10;
	int from = 1;
	int step = 1;
	int x;
	int i;

	if (argc > 1) n = atoi(argv[1]);
	if (argc > 2) from = atoi(argv[2]);
	if (argc > 3) step = atoi(argv[3]);

	x = from;
	for (i = 0; i < n; i++) {
		printf("%d\n", x);
		x += step;
	}
	return(0);
}
