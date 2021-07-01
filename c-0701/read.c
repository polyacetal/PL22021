#include <stdio.h>

int main(void){
	FILE *fp;
	int x;
	int s;

	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		perror("fopen() 失敗");
		return(1);
	}

	while (1){
		s = fscanf(fp,"%d", &x);
		if (s == EOF) break;

		printf("%d\n", x);
	}
	fclose(fp);
	return(0);
}
