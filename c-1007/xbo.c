#include <stdio.h>

int main(void)
{
	unsigned int data;
	unsigned char *p;

	printf("16進数 > ");
	scanf("%X", &data);

	p = (unsigned char *)&data;

	printf(" %02X", p[3]);
	printf(" %02X", p[2]);
	printf(" %02X", p[1]);
	printf(" %02X", p[0]);
	printf("\n");

	return(0);
}
