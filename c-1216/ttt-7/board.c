#include <stdlib.h>
#include "board.h"

int Get(Board *bd, int y, int x)
{
	if (x < 0) return (-1);		/* ハミ出し禁止 */
	if (x >= bd->size) return (-1);	/* （バッファオーバラン防止） */
	if (y < 0) return (-1);
	if (y >= bd->size) return (-1);

	return (bd->cell[y*bd->size + x]);
}

void Set(Board *bd, int y, int x, int v)
{
	if (x < 0) return;		/* ハミ出し禁止 */
	if (x >= bd->size) return;	/* （バッファ−バラン防止） */
	if (y < 0) return;
	if (y >= bd->size) return;

	bd->cell[y*bd->size + x] = v;
}

void Clear(Board *bd)
{
	int	y, x;

	for (y = 0; y < bd->size; y++) {
		for (x = 0; x < bd->size; x++) {
			bd->cell[y*bd->size + x] = 0;
		}
	}
}

void Free(Board *bd)
{
	if (bd == NULL) return;
	free(bd->cell);
	free(bd);
}

Board *New(int n)
{
	Board	*bd;

	bd = (Board *)malloc(sizeof(Board));
	if (bd == NULL) return (NULL);

	bd->size = n;
	bd->cell = (int *)malloc(sizeof(int)*n*n);
	if (bd->cell == NULL) {
		free(bd);
		return (NULL);
	}
	return (bd);
}
