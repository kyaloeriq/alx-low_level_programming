#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _realloc - reallocates a memory block using malloc and free
 * @old_size: size of 1st mem block
 * @new_size: size of 2nd mem block
 * Return: pointe to new mem allocation
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *ptr1;

	ptr = malloc(old_size);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	ptr1 = malloc(new_size);
	if (ptr == NULL)
	{
		if (ptr1 == NULL)
			return (NULL);
		return (ptr1);
	}
	if (ptr1 != NULL)
	{
		if (new_size > old_size)
		{
			memcpy(ptr1, ptr, old_size);
		}
		else
		{
			memcpy(ptr1, ptr, new_size);
		}
	}
	free(ptr);
	return (ptr1);
}
