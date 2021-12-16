#ifndef SUB_H
#define SUB_H

#define MAXLEN 1024
typedef struct {
	int data[MAXLEN];
	int len;
}Array;

extern void GenSeq(Array *a, int n, int from, int step);

extern int Sum(Array *a);

#endif
