#include <stdio.h>
#include <string.h>

int main(void) {
	char s[10] = "abc";
	printf("初期状態 [%s]\n", s);

	strcpy(s, "de");
	printf("代入後 [%s]\n", s);
	if(strcmp(s, "de") == 0) {
		printf("BING\n");
	}

		return(0);
}
