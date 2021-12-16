#ifndef BOARD_H
#define BOARD_H
typedef struct {
	int	size;
	int	*cell;
} Board;
extern int Get(Board *bd, int y, int x);
extern void Set(Board *bd, int y, int x, int v);
extern void Clear(Board *bd);
extern void Free(Board *bd);
extern Board *New(int n);
#endif
