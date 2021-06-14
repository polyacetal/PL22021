#include <stdio.h>
#include <math.h>
#define CENTER 10     //中心位置の移動

int void_plot(int y) {
	int i;
	int point;
	point = y + CENTER;
	for (i = 0; i < point; i++) {
		printf(" ");
	}
	printf("*\n");
}

int main(void) {
	int x;     //for文のループ制御
	int y;     //sinの値
	double z;  //sinに渡す引数のラジアンを格納する変数

	for (x = 0; x < 13; x++) {
		z = x *3.14 / 6;  //30度ずつラジアンにする
		y = sin(z) * 10;  //sinの引数の単位はラジアン 見えやすくするため10倍
		void_plot(y); 
	}
	return(0);
}
