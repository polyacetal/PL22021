#include <stdio.h>

int main(void){
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	int x;
	int s;
	int err = 0;

	fp1 = fopen("data.txt", "r");
	if (fp1 == NULL) {
		perror("入力のfopen() 失敗");
		err = 1; goto END;
	}

	fp2 = fopen("copy.txt", "w");
	if (fp2 == NULL) {
		perror("出力のfopen() 失敗");
		err = 2; goto END;
	}

	while (1){
		s = fscanf(fp1,"%d", &x);
		if (s == EOF) break;

		fprintf(fp2, "%d\n", x);
	}
END:
	if (fp1 != NULL) fclose(fp1);
	if (fp2 != NULL) fclose(fp2);
	return(err);
}
