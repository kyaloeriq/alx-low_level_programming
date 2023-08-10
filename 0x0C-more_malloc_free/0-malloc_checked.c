#include <stdio.h>
#include <stdlib.h>
/**
 * malloc_checked - allocates memory using malloc
 * @b: useless param
 * Return: pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	unsigned int *ptr;
	(void) b;

	ptr = malloc(sizeof(unsigned int));

	if (ptr == NULL)
	{
		return ("NULL, 98");
	}
	return (ptr);
	free(ptr);
	return (0);
}

