#include <stdio.h>

int main(void){
	FILE *fp;
	int x;
	int s;

	fp = fopen("data.txt", "w");
	if (fp == NULL) {
		perror("fopen() 失敗");
		return(1);
	}

	printf("整数データ (最後に Ctrl+D) > ");
	while (1){
		s = scanf("%d", &x);
		if (s == EOF) break;

		fprintf(fp, "%d\n", x);
	}
	fclose(fp);
	return(0);
}
