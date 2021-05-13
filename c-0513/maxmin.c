#include <stdio.h>

int main(void)
{
	int max, min, scr, prf;

	scr = 0;
	max = 0;
	min = 100;
	prf = 0;
	printf("このテストは何点満点ですか？ > ");
	scanf("%d", &prf);
	do {
		printf("得点 > ");
		scanf("%d", &scr);
		if (scr > max && scr <= prf) {
			max = scr;
		} else if (scr < min && scr >= 0) {
			min = scr;
		} else if (scr > prf){
			printf("このテストは%d点満点です\n", prf);
		}
	} while (scr > 0);

	printf("最高点 = %d\n", max);
	printf("最低点 = %d\n", min);

		return(0);
}
