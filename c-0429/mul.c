#include <stdio.h>

int main(void)
{
		int num;

		double val;

		double total;
		
		printf("整数と実数を入力せよ >");
		scanf("%d %lf", &num, &val);

		total = num*val;

		printf("%d * %f = %f\n", num, val, total);

		return(0);
}
