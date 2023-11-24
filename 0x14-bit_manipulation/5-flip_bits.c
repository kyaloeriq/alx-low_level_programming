#include <stdio.h>
#include "main.h"
/**
 * flip_bits - returns number of bits to flip to get from one number to another
 * @n: 1st number
 * @m: 2nd number
 * Return: number of bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_rslt = n ^ m; /*XOR two numbers to find differing bits*/
	unsigned int count = 0;

	while (xor_rslt)
	{
		count += xor_rslt & 1;
		xor_rslt >>= 1;
	}
	return (count);
}
