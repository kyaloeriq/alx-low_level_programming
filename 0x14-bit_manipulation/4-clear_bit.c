#include <stdio.h>
#include "main.h"
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to bits
 * @index: index, starting from 0
 * Return: 1 if it worked, -1 if an error occured
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);/*Checks if the index is within a valid range*/
	*n = *n & ~(1UL << index);/*Clear the bit at the specified index*/
	return (1);
}
