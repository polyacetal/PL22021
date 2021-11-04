#include <stdio.h>

int main(void)
{
	char c;
	int n = 0;

//	printf("テキスト > ");

	while (1) {
		if (scanf("%c", &c) == EOF) break;
		printf("%c", c);
		n++;
	}
	if (n == 0) perror("入力が無いぜ");

	return(0);
}
