#include <stdio.h>

int main(void) {
	int a[3] = { 10, 11, 12 };
	int b[3] = { 20, 21, 22 };
	int c[3] = { 30, 31, 32 };
	int i;

//	b[4] = 99999;

for (i = 0; i < 3; i++) {
	printf("a[%d] = %d\n", i, a[i]);
	printf("b[%d] = %d\n", i, b[i]);
	printf("c[%d] = %d\n", i, c[i]);
}

	return(0);
}
