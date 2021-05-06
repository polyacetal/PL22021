#include <stdio.h>

int main(void)
{
		double x,y,z;
		
		while (1) {
				printf("実数2個 >");
				scanf("%lf %lf", &x, &y);
				z = x / y;
				printf("%f / %f = %f\n", x, y, z);
		}
		return(0);
}
