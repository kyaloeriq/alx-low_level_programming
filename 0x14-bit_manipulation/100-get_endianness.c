#include <stdio.h>
#include "main.h"
/**
 * get_endianness - checks the endianness
 * Return: 0 if big indian, 1 if little indian
 */
int get_endianness(void)
{
	int n = 1;

	if (*(char *) &n == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
