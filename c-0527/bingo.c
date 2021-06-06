#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NF 16

int main(void)
{
	int r;
	int f[NF] = {};
	int n = 5;
	srand(time(NULL));

	while (n > 0) {
		r = rand()%(NF-1) + 1;
		if (f[r] == 1) continue;
		f[r] = 1;
		n--;
	}

	printf("B\n");
	for (r = 1; r < NF; r++) {
		if (f[r] == 0) continue;
		printf("%d\n", r);
	}


		return(0);
}
