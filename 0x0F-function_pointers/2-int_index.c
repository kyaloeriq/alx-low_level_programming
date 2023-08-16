#include <stddef.h>
#include "function_pointers.h"
/**
 * int_index - searches for an integer
 * @array: array
 * @size: number of elements in the array
 * @cmp: pointer to function to compare values
 * Return: -1 if no element matches
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int a;

	if (array != NULL && cmp != NULL)
	{

		for (a = 0; a < size; a++)
		{
			if (cmp(array[a]) != 0)
			{
				return (a);
			}
		}
	}
	return (-1);
}

