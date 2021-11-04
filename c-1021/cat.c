#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cat(FILE *fp)
{
	char c;

	while (1) {
		if (fscanf(fp, "%c", &c) == EOF) return;
		printf("%c", c);
	}
}

void fatal(char *msg, char *op)
{
	fprintf(stderr, "%s:%s\n", msg, op);
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	FILE *fp;
	int i;

	if (argc == 1) cat(stdin);
	for (i = 1; i < argc; i++) {
		fp = fopen(argv[i], "r");
		if (strcmp(argv[i], "-") == 0) fp = stdin;
		if (fp == NULL) fatal("fopen()失敗", argv[i]);

		cat(fp);
		fclose(fp);
	}

	return(EXIT_SUCCESS);
}
