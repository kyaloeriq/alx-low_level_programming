#include "main.h"
#include <stdlib.h>
/**
 * free_grid - frees a 2 dimensional grid previously created
 * @height: height
 * @ptr: pointer
 * Return: 0
 */
void free_grid(int **ptr, int height)
{
	int a;
	**ptr = 0;

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
