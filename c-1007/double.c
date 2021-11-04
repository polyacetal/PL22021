#include <stdio.h>

int main(void)
{
	double data = -10.5;
	unsigned char *p;
	int i;

	p= (unsigned char *)&data;

	printf("%f\n", data);

	for (i = 0; i < 8; i++) {
		printf(" %02X", p[i]);
	}
	printf("\n");

	return(0);
}
