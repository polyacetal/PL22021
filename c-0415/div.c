#include <stdio.h>
int main(void)
{
		int x, y;
		int z;

		while (1) {
				printf("2個の整数値 >");
				if(scanf("%d %d", &x, &y) == EOF) break;

				if (y == 0) {
						printf("ゼロでは割れません. \n");
				}else{
						z = x/y;
						printf("%d/%d = %d\n", x,y,z);
				}
	    }
		printf("\nおつかれさまでした. \n");
		return(0);
}
