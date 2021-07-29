#include <stdio.h>

int main(void) {
	char c;

	for(c = 'a'; c <= 'z'; c++) {
		printf("%3d [%c]\n", c, c);
	}
		return(0);
}
