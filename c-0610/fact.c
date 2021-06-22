#include <stdio.h>

int fact1(int n) {
	int i;
	int j = 1;
	for(i = n; i >= 1; i--) {
		j = j * i;
		printf("%d", j);
	}
	return(j);
}
int fact2(int n){
	int i;
	if (n == 0) {
		return(1);
	} else {
		i = fact2(n-1) * n;
		return (i);
	}
}

int main(void) {
	int i;
	i = fact2(5);
	printf("%d\n", i);

		return(0);
}
