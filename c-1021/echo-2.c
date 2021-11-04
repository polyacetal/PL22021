#include <stdio.h>
#include <stdlib.h>

void fatal(char *msg)
{
	fprintf(stderr, "echo: %s\n", msg);
	exit(EXIT_FAILURE);
}
int main(int argc, char *argv[])
{
	int i;

	if (argc < 2) fatal("引数が不足.何か指定して");

	for (i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}
	printf("\n");

	return(EXIT_SUCCESS);
}
