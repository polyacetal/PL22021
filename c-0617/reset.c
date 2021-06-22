#include <stdio.h>

void reset(int *p) {
	printf("sub():1: *p = %d\n", *p);
	*p = 0;
	printf("sub():2: *p = %d\n", *p);
}

int main(void){
	int x = 123;

	printf("main():1: x = %d\n", x);
	reset(&x);
	printf("main():2: x = %d\n", x);

		return(0);
}
