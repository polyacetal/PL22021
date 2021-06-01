#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int r;
	int x;
	srand(time(NULL));

	printf("ロシアンルーレットを始めるよー\n");
	r = rand()&6;

	while (1) {
		printf("弾倉を回す？\n");
		printf("1以上:回して撃つ, 0:そのまま撃つ, -1以下:パス > ");
		scanf("%d", &x);

		if (x < 0) continue;
		if (x > 0) r = rand()%6;
		printf("カチッ...\n");
		printf("%d\n", r);
		if (r == 0) break;

		printf("セーフ\n");
		r--;
	}
	printf("バーン...\n");
	printf("終了\n");

		return(0);
}
