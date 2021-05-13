#include <stdio.h>

int main(void)
{
	int n=0, m=0, a=0;

	for (n = 1; n <= 9; n++) {
		printf("%dの段", n);
		for (m = 1; m <= 9; m++) {
			a = m * n;
			if ( m == 9) {
				printf(" %d\n", a);
			} else if ( a / 10 == 0){
				printf(" %d ", a);
			} else {
				printf(" %d", a);
			}
		}
	}

		return(0);
}
