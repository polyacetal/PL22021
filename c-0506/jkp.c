#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int cp, npc;

	srand(time(NULL));

	while (1) {
		(int)npc = (rand()%3)*2.5;
		printf("ジャンケンポン {0, 2, 5} >");
		scanf("%d", &cp);
	}

		return(0);
}
