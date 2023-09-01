#include <stdio.h>
#include "main.h"
/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: number containing bits to be flipped
 * @m: bits to be flipped
 * Return: number of bits to be flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip = n ^ m;
	unsigned int counter = 0;

	while (flip > 0)
	{
		counter += flip & 1;
		flip >>= 1;
	}
	return (counter);
}
