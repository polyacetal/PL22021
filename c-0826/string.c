#include <stdio.h>
#include <string.h>

int mystrlen1(char s[])
{
	int n = 0;

	while (s[n]) {
		n++;
	}
	return(n);
}

int mystrlen2(char *s)
{
	int n = 0;

	while (*s) {
		n++;
		s++;
	}
	return(n);
}

char *mystrcpy(char *dst, char *src)
{
	char *r;
	r = dst;
	while (1) {
		*dst = *src;
		if(*src == '\0') break;
		src++;
		dst++;
	}
	return(r);
}

int mystrcmp(char *s1, char *s2)
{
	while (*s1 == *s2) {
		if (*s1 == '\0') break;
		s1++;
		s2++;
	}
	return(*s1 - *s2);
}

#define BUFLEN 256
#define BUFFMT "%255s"

int main(void) 
{
	char buf[BUFLEN];

	char *fmt = BUFFMT;

	int n;
	int d;
	char pre[BUFLEN] = "";

	while (1) {
		printf("文字列(%d文字以内) > ", BUFLEN-1);
		scanf(fmt, buf);

		//n = strlen(buf);
		//n = mystrlen1(buf);
		n = mystrlen2(buf);
		printf("文字数=%d\n", n);

		//d = strcmp(buf, pre);
		d = mystrcmp(buf, pre);
		if (d == 0) break;

		//strcpy(pre, buf);
		mystrcpy(pre, buf);
	}
	return(0);
}
