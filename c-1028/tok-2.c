#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *sgettok(char *str, char *tok, int n)
{
	char *s;
	char *t;
	int i;
	int d0, d1;

	s = str;
	t = tok;

	while (isspace(*s)) s++;

	d0 = isdigit(*s);
	n--;
	for (i = 0; i < n; i++) {
		if (*s == '\0') break;
		if (isspace(*s)) break;

		d1 = isdigit(*s);
		if (d1 != d0) break;

		*t = *s; t++;
		s++;

		d0 = d1;
	}
	if (t == tok) return (NULL);
	*t = '\0';

	return (s);
}

#define BUFLEN 256

int main(void)
{
	char line[BUFLEN];
	char tok[BUFLEN];
	char *expr;

	while (1) {
		printf("数式 > ");
		if (fgets(line, BUFLEN, stdin) == NULL) break;

		expr = line;
		while (1) {
			expr = sgettok(expr, tok, BUFLEN);

			if (expr == NULL) break;
			if (strcmp(tok, "quit") == 0) goto END;
			printf("[%s]\n", tok);
		}
	}
END:
	printf("終了\n");
	return (EXIT_SUCCESS);
}
