#include <stdio.h>

int div(int x, int y) {
	int z = 0;

	while (x >= y) {
		x = x - y;
		z++;
	}
	return (z);
}

int main(void) {
	int x, y, z;

	//入力部
	printf("x, y > ");
	scanf("%d %d", &x, &y);

	//計算部
	z = div(x, y);

	//出力部
	printf("%d / %d = %d\n", x, y, z);

		return (0);
}
