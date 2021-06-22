#include <stdio.h>

void print(int *p, int n) {
	int i;
	printf("{ ");
	for(i = 0; i < n; i++) {
		printf("%d ", p[i]);
	}
	printf("}\n");
}

void reset(int *p, int n, int v) {
	int i;
	for(i = 0; i < n; i++) {
		p[i] = v;
	}
}

int check(int *p, int n, int *np, int *nm) {
	int i;
	int nz = 0;
	*np = 0;
	*nm = 0;
	for(i = 0; i < n; i++) {
		if (p[i] > 0) {
			(*np)++;
		} else if (p[i] < 0) {
			(*nm)++;
		} else if (p[i] == 0) {
			nz++;
		}
	}
	return (nz);
}

void input(int *p, int n) {
	int i;
	int x;
	for(i = 0; i < n; i++) {
		printf("%d個目の数 > ", i+1);
		scanf("%d", &x);
		p[i] = x;
	}
}

void copy(int *p, int *q, int n) {
	int i;
	for(i = 0; i < n; i++) {
		q[i] = p[i];
	}
}

#define NUM 5

int main(void) {
	int a[NUM];
	int b[NUM];
	int np, nm, nz;

	print(a, NUM);

	nz = check(a, NUM, &np, &nm);
	printf("ゼロ | 正 | 負 : %d | %d | %d 個\n", nz, np, nm);

	reset(a, NUM, 7);
	print(a, NUM);

	nz = check(a, NUM, &np ,&nm);
	printf("ゼロ | 正 | 負 : %d | %d | %d 個\n", nz, np, nm);

	input(a, NUM);
	print(a, NUM);

	copy(a, b, NUM);
	print(b, NUM);

		return(0);
}
