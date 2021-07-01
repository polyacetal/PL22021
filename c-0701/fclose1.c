#include <stdio.h>

int main(void)
{
	FILE *fp;
	int n = 0;

	while (1) {
		fp = fopen("fclose1.c", "r");
		if (fp ==NULL) break;
		n++;
		printf("%d回OK\n", n);
	}
	fclose(fp);
		return(0);
}
