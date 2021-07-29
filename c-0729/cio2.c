#include <stdio.h>

int main(void) {
	char c;

	printf("半角英数字を連続入力 > ");
	while(1) {
		c = getchar();
		if(c == EOF) break;
		putchar(c);
	}

		return(0);
}
