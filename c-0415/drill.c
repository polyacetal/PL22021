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

		printf("ð©è¨ç®ããªã«\n");

		while (1) {
				x = rand()%100 + 1;
				y = rand()%10 + 1;
				printf("âªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâªâª\n");
				printf("%d åã®ð©ããããã¾ãã. \n", x);
				printf("%d äººã§å±±åããã¾ããã. \n", y);
				printf("ä¸äººåã¯ä½åã§ããï¼ >");
				if(scanf("%d", &a) == EOF) break;
				z = x/y;
				
				if (a == z) {
						printf("â\n");
						success = success + 1 ;
				}else{
						printf("â :æ­£è§£ã¯%dã§ã.", z);
						failure = failure + 1 ;
				}
		}
		all = success + failure;
		rate = (success/all)*100;
		printf("\n---------------------------------------\n");
		printf("æç¸¾è¡¨\n");
		printf("æ­£ç­æ° : %d\n", success);
		printf("èª¤ç­æ° : %d\n", failure);
		printf("åè¨åç­æ° : %d\n", all);
		printf("æ­£ç­ç : %d\n", rate);
		if (rate >= 60){
				printf("ä¸è¨ã®æ­£ç­çããããªãã¯é»ç¹ã§ã.\n");
		}else{
				printf("ä¸è¨ã®æ­£ç­çããããªãã¯èµ¤ç¹ã§ã.\n");
				printf("æ¬¡åã¯é»ç¹ãç®æãã¾ããã.\n");
		}
		printf("----------------------------------------\n");
		printf("\nããã¾ã. \n");
		return(0);
}
