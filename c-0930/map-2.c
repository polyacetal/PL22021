#include <stdio.h>

int main(void) {
	char a[3];
	int b[3];
	double c[3];
	int i;

//	printf("(アドレス) : (変数名)\n");
for (i = 0; i < 3; i++) {
	printf("%p : a[%d]\n", &a[i], i);
	printf("%p : b[%d]\n", &b[i], i);
	printf("%p : c[%d]\n", &c[i], i);
}
printf("%p : i\n", &i);

	return(0);
}
