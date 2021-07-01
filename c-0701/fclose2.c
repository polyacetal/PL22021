#include <stdio.h>

int main(void)
{
	FILE *fp;
	int n = 0;

	//fclose(fp);

	/*
	fp = fopen("notexist.txt", "r");
	fclose(fp);
	*/

	fp = fopen("fclose2.c", "r");
	fclose(fp);
	fclose(fp);
	return(0);
}
