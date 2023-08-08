#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width
 * @height: height
 * Return: pointer to a 2 dimensional array of integers, NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int a;
	int b;
	int **ptr;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	ptr  = (int **)malloc(height * sizeof(int *));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (a = 0; a < height; a++)
	{
		ptr[a] = (int *)malloc(width * sizeof(int));
		if (ptr[a] == NULL)
		{
			for (b = 0; b < a; b++)
			{
				free(ptr[b]);
			}
			free(ptr);
			return (NULL);
		}
		for (b = 0; b < width; b++)
		{
			ptr[a][b] = 0;
		}
	}
	return (ptr);
}
