#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * binary_to_uint - converts binary number to unsigned int
 * @b: string of 0 and 1 char
 * Return: converted number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);
	while (*b != '\0')
	{
		if (*b == '0' || *b == '1')
		{
			result = result * 2 + (*b - '0');
			b++;
		}
		else
		{
			return (0);/* Return 0 if string contains char other than 0 and 1 */
		}
	}
	return (result);
}
