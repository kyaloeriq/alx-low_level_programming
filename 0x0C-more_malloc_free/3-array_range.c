#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * array_range - creates an array of integers
 * @min: min value
 * @max: maximum value
 * Return: pointer to the newly created array
 */
int *array_range(int min, int max)
{
	int *range, i;

	if (min > max)
	{
		return (NULL);
	}
	range = (int *)malloc((max - min + 1) * sizeof(int));
	if (range == NULL)
	{
		return (NULL);
	}

	for (i = 0; min <= max; i++, min++)
	{
		range[i] = min;
	}
	return (range);
}
