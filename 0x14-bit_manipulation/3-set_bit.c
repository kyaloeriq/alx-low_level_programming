#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to bits
 * @index: index, starting from 0
 * Return: 1 if it worked, -1 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);/*Checks if index is within a valid range*/
	*n = *n | (1 << index);/*Set the bit at specified index to 1*/
	return (1);
}
