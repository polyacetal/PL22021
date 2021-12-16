#ifdef DEBUG
#include <stdio.h>
#endif
#include "sub.h"

void GenSeq(Array *a, int n, int from, int step)
{
	int i;
	int x = from;

	a->len = n;
	for (i = 0; i < n; i++) {
#ifdef DEBUG
		printf("DEBUG: %d\n", x);
#endif
		a->data[i] = x;
		x += step;
	}
}

int Sum(Array *a)
{
	int s = 0;
	int i;

	for (i = 0; i < a->len; i++) {
		s += a->data[i];
	}
	return (s);
}
