#include <stdio.h>
#include <stdlib.h>
#include "sub.h"

int main(int argc, char *argv[])
{
	Array a;
	int n = 10, from = 1, step = 1;

	if (argc > 1) n = atoi(argv[1]);
	if (n > MAXLEN) return (EXIT_FAILURE);
	if (argc > 2) n = atoi(argv[2]);
	if (argc > 3) n = atoi(argv[3]);

	GenSeq(&a, n, from, step);
	printf("%d\n", Sum(&a));

	return(EXIT_SUCCESS);
}
