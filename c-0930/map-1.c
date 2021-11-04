#include <stdio.h>

int main(void) {
	char a;
	int b;
	double c;

	printf("(アドレス) : (変数名)\n");
	printf("%p : a\n", &a);
	printf("%p : b\n", &b);
	printf("%p : c\n", &c);

	return(0);
}
