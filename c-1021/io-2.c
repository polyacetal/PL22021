#include <stdio.h>

int main(void)
{
	char c;
	int n = 0;

//	printf("テキスト > ");

	while (1) {
		if (fscanf(stdin, "%c", &c) == EOF) break;
		fprintf(stdout, "%c", c);
		n++;
	}
	if (n == 0) fprintf(stderr, "入力が無いぜ");

	return(0);
}
