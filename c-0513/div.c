#include <stdio.h>

int main(void)
{
	int x, y, z;
	int m;

	printf("自然数 x, y > ");
	scanf("%d %d", &x, &y);

	z = 0;
	m = x;

	while (m >= y) {
		m = m - y;
		z++;
	}

	printf("%d / %d = %d ... %d\n", x, y, z, m);

		return(0);
}
