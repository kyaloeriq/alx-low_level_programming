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

	if (n == 0)
	{
		putchar('0');
		return;
	}

	print_binary(n >> 1);/* shifts the bits to the right, effectively dividing the number by 2 */
	putchar((n & 1) + '0');
}
