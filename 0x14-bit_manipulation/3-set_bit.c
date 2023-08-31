#include <stdio.h>
#include "main.h"
/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: number from which the bit will be set
 * @index: position of the bit that will be set
 * Return: 1 if it works, -1 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int k = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	*n |= k;
	return (1);
}
