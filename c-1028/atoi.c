#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int myatoi(char *str)
{
	int val;
	int sgn;
	char *s;

	s = str;
	while (isspace(*s)) s++;

	sgn = +1;
	if (*s == '-') {
		sgn = -1; s++;
	} else if (*s == '+') {
		s++;
	}

	val = 0;
	while (isdigit(*s)) {
		val = val*10 + (int)(*s - '0');
		s++;
	}
	return (val*sgn);
}

#define BUFLEN 256

int main(void)
{
	char buf[BUFLEN];

	while (1) {
		printf("行文字列 > ");
		if (fgets(buf, BUFLEN, stdin) == NULL) break;
		printf("atoi()   :%d\n", atoi(buf));
		printf("myatoi() :%d\n", myatoi(buf));
		printf("\n");
	}
	printf("終了\n");
	return(EXIT_SUCCESS);
}
