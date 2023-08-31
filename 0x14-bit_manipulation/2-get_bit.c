#include <stdio.h>
#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index
 * @index: index of the bit to retrieve
 * @n: number to extract the bit from
 * Return: value of bit at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int m = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	return ((n & m) ? 1 : 0);
}
