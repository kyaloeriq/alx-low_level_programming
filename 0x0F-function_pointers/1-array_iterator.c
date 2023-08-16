#include <stddef.h>
#include "function_pointers.h"
/**
 * array_iterator - function executing on each element
 * @array: array containing elements
 * @size: size of the array
 * @action: pointer to the function you need to use
 * Return: success
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t a;

	if (array != NULL &&  action != NULL)
	{
		for (a = 0; a < size; a++)
		{
			action(array[a]);
		}
	}
}
