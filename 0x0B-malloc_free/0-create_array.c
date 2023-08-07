#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char
 * @size: size of array
 * @c: array of chars created
 * Return: a pointer to the array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int b;

	if (size == 0)
	{
		return (NULL);
	}
	array = (char *)malloc(size * sizeof(char));
	if (array == NULL)
	{
		return (NULL);
	}

	for (b = 0; b < size; b++)
	{
		array[b] = c;
	}
	return (array);
}


