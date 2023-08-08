#include "main.h"
#include <stdlib.h>
/**
 * free_grid - frees a 2 dimensional grid previously created
 * @height: height
 * @grid: useless param
 * Return: 0
 */
void free_grid(int **grid, int height)
{
	int a;
	int **ptr;

	ptr  = 0;
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
