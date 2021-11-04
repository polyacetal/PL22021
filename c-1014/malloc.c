#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *a;
	int n;

	while (1) {
		a = (char *)malloc(1024*1024);
		if (a == NULL) break;
		n++;
		printf("%d回OK\n", n);
	}

	return(0);
}
