#include <stdio.h>

#define BUFLEN 10

int main(void) {
	char buf[BUFLEN];

	printf("半角英数字を連続入力 > ");
	while(1) {
		if(scanf("%s", buf) == EOF) break;
		printf("[%s]", buf);
	}

		return(0);
}
