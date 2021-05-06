#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
		int x,y;
		int z;

		if (argc != 3) return (1);
		x = atoi(argv[1]);
		y = atoi(argv[2]);
		if (y==0) return (1);
		z = x/y;
		printf("%d/%d = %d\n", x, y, z);
		return (0);
}
