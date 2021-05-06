#include <stdio.h>

int main(void)
{
	int cm, kg, n;
	double m, bmi;

	printf("BMIによるメタボ診断\n");
	while (1) {
		printf("----\n");
		printf("身長[cm] 体重[kg] >");
		scanf("%d %d", &cm, &kg);

		m = (double)cm/100.0;
		bmi = kg/(m*m);

		printf("BMI = %.1f\n", bmi);

		// 体型診断
		if (bmi < 18.5) {
			printf("低体重(やせ型) \n");
		} else if (bmi < 25.0) {
			printf("普通体重\n");
		} else {
			n = (int)((bmi - 25.0)/5.0) + 1;
			if (n > 4) n = 4;
			printf("肥満 (%d度) \n", n);
		}
	}

		return(0);
}
