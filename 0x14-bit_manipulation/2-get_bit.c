#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index
 * @n: bits
 * @index: index starting from 0
 * Return: value of bit at index or -1 incase of an error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);/*Checks if index is within a valid range*/

	return ((n >> index) & 1);/*Shift and mask to get the bit value*/
}
