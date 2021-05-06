#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		int x,y,z;
		int a;
		int success = 0;
		int failure = 0;
		int all = 0;
		int rate =0;

		printf("💩計算ドリル\n");

		while (1) {
				x = rand()%100 + 1;
				y = rand()%10 + 1;
				printf("♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪\n");
				printf("%d 個の💩をもらいました. \n", x);
				printf("%d 人で山分けしましょう. \n", y);
				printf("一人分は何個ですか？ >");
				if(scanf("%d", &a) == EOF) break;
				z = x/y;
				
				if (a == z) {
						printf("○\n");
						success = success + 1 ;
				}else{
						printf("☓ :正解は%dです.", z);
						failure = failure + 1 ;
				}
		}
		all = success + failure;
		rate = (success/all)*100;
		printf("\n---------------------------------------\n");
		printf("成績表\n");
		printf("正答数 : %d\n", success);
		printf("誤答数 : %d\n", failure);
		printf("合計回答数 : %d\n", all);
		printf("正答率 : %d\n", rate);
		if (rate >= 60){
				printf("上記の正答率よりあなたは黑点です.\n");
		}else{
				printf("上記の正答率よりあなたは赤点です.\n");
				printf("次回は黑点を目指しましょう.\n");
		}
		printf("----------------------------------------\n");
		printf("\nおしまい. \n");
		return(0);
}
