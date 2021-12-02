#include <stdio.h>

typedef struct {
	double re, im;
	char *text;
} Complex;

void PrintC(char *name, Complex *z)
{
	printf("%s = %f + %f i ... %s\n", name, z->re, z->im, z->text);
}

int main(void)
{
	Complex a;
	Complex b = {0.0, 1.0, "虚数単位"};
	Complex *p;

//b = 2 * b; //構造体の計算...NG(独自に関数等を定義せよ)
	PrintC("b", &b);

	a = b;	//構造体同士の一括代入(全メンバのコピー)
	if (a == b) printf("Bingo!\n");	//構造体同士の比較...NG(独自に関数等ry)
	PrintC("a", &a);

//b = {0.0, 0.0, "ゼロ"};	//宣言以外での初期化...NG
	b.re = 0.0;
	b.im = 0.0;
	b.text = "ゼロ";

//b = InitC(0.0, 0.0, "ゼロ");

	PrintC("b", &b);

	p = &b;
	PrintC("b", p);

	a = *p;
	PrintfC("a", &a);

	return(0);
}
