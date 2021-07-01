#include <stdio.h>

int main(void){
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	FILE *fp3 = NULL;
	int x;
	int s;
	int i = 0;
	int err = 0;

	fp1 = fopen("data2.txt", "r");
	if (fp1 == NULL) {
		perror("入力のfopen() 失敗");
		err = 1; goto END;
	}

	fp2 = fopen("col1.txt", "w");
	if (fp2 == NULL) {
		perror("出力1のfopen() 失敗");
		err = 2; goto END;
	}

	fp3 = fopen("col2.txt", "w");
	if (fp3 == NULL) {
		perror("出力2のfopen() 失敗");
		err = 3; goto END;
	}

	while (1){
		s = fscanf(fp1,"%d", &x);
		if (s == EOF) break;
		i++;
		if (i%2 == 1) {
			fprintf(fp2, "%d\n", x);
		} else if (i%2 == 0) {
			fprintf(fp3, "%d\n", x);
		}
	}
END:
	if (fp1 != NULL) fclose(fp1);
	if (fp2 != NULL) fclose(fp2);
	if (fp3 != NULL) fclose(fp3);
	return(err);
}
