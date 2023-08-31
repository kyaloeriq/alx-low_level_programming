#include <stdio.h>
#include "main.h"
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: number from which the bit is to be set
 * @index: position of the bit to be set
 * Return: 1 if it works, -1 if it doesn't
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int a = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	a = ~a;
	*n &= a;
	return (1);
}
