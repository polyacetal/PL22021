#include <stdio.h>

int main(void) {
	char c;

	printf("半角英数字を連続入力 > ");
	while(1) {
		if(scanf("%c",&c) == EOF) break;
		printf("[%c]", c);
	}

		return(0);
}
