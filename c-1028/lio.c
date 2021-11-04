#include <stdio.h>
#include <stdlib.h>

char *myfgets(char *buf, int n, FILE *fp)
{
	int i;
	int c;
	char *s;

	s = buf;
	n--;
	for (i = 0; i < n; i++) {
		c = fgetc(fp);
		if (c == EOF) break;

		*s = (char)c;
		s++;

		if (c == '\n') break;
	}
	if (s == buf) return(NULL);
	*s = '\0';
	return (buf);
}

int myfputs(char *s, FILE *fp)
{
	while (*s != '\0') {
		if (fputc((int)*s, fp) == EOF) return (EOF);
		s++;
	}
	return (0);
}

#define BUFLEN 256

int main(void)
{
	char buf[BUFLEN];

	while (1) {
		//if (fgets(buf, BUFLEN, stdin) == NULL) break;
		//fputs(buf, stdout);
		
		if (myfgets(buf, BUFLEN, stdin) == NULL) break;
		myfputs(buf, stdout);
	}
	return(EXIT_SUCCESS);

}
