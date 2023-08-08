#include "main.h"
#include <stdlib.h>
/**
 * free_grid - frees a 2 dimensional grid previously created
 * @height: height
 * @grid: useless param
 */
void free_grid(int **grid, int height)
{
	int a;
	int **ptr;

	ptr  = (int **)malloc(height * sizeof(int *));
	(void)grid;

	if (ptr == NULL || height <= 0)
	{
		return;
	}
	for (a = 0; a < height; a++)
	{
		free(ptr[a]);
	}
	free(ptr);
}
