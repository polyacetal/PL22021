#include <stdio.h>

int main(void)
{
	int data = 0x1234ABCD;

	unsigned char *p;

	p = (unsigned char *)&data;

	printf("%X\n", data);

	printf(" %02X", p[0]);
	printf(" %02X", p[1]);
	printf(" %02X", p[2]);
	printf(" %02X", p[3]);
	printf("\n");

	return(0);
}
