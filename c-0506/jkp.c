#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int pc, npc, flag, ans = 0, all = 0, win = 0;

	srand(time(NULL));

	while (1) {
		flag = 0;
		npc = (rand()%3)*2.5;
		printf("ジャンケンポン {0, 2, 5} >");
		if (scanf("%d", &pc) == EOF) break;

		switch (pc) {
			case 0:printf("あなたはグーを出しました\n"); break;
			case 2:printf("あなたはチョキを出しました\n"); break;
			case 5:printf("あなたはパーを出しました\n"); break;
			default :printf("わ け が わ か ら な い よ\n"); flag = 1;
		}

		switch (npc) {
			case 0:printf("私はグーを出しました\n"); break;
			case 2:printf("私はチョキを出しました\n"); break;
			case 5:printf("私はパーを出しました\n"); break;
		}

		ans = (pc - npc) / 2;

		if (flag == 0) {
			if (pc == npc){
				printf("アイコ\n");
			} else if (ans == -1 || ans == 2){
				printf("あなたの勝ち\n");
				win = win + 1;
			} else if (ans == 1 || ans == -2){
				printf("私の勝ち\n");
			}
		} else {
			printf("もう一度お試しください\n");
			all = all - 1;
		}
	all = all + 1;
	}

	printf("\n成績発表\n");
	printf("合計勝負数:%d\n", all);
	printf("あなたの勝利数:%d\n", win);

		return(0);
}
