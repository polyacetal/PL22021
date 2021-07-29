#include <stdio.h>
#define BUFLEN 16

int main(void) {
	char buf1[BUFLEN] = "buf1";
	char buf2[BUFLEN] = "buf2";
	char buf3[BUFLEN] = "buf3";

	while(1) {
		printf("buf2 (15文字以内) > ");
		if(scanf("%s", buf2) == EOF) break;
		//if(scanf("%15s", buf2) == EOF) break;
		
		printf("buf1:[%s]\n", buf1);
		printf("buf2:[%s]\n", buf2);
		printf("buf2:[%s]\n", buf3);
		printf("\n");
	}

		return(0);
}
