#include <stdio.h>

int sign(int x)
{
	int y; 

	if (x > 0) {
		y = +1;
	}else if (x == 0) {
		y = 0;
	}else if (x < 0) {
		y = -1;
	}

	return (y);
}

int main(void)
{
	int x;
	int y;

	while (1){
		//入力部
		printf("整数 > ");
		scanf("%d", &x);

		//計算部
		y = sign(x);

		//出力部
		printf("%d\n", y);
	}

		return(0);
}
