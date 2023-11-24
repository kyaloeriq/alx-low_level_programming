#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: binary string
 * Return: converted number or 0
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
	print_binary(n >> 1);/*shifts bits to the right, dividing the number by 2*/

	putchar((n & 1) + '0');
}
