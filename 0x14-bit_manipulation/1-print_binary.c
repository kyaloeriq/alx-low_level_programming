#include <stdio.h>
#include "main.h"
/**
 * print_binary - prints the binary representation of a number
 * @n: No.whos binary rep.is to be printed
 * Return: binary rep
 */
void print_binary(unsigned long int n)
{
	int rep = sizeof(unsigned long int) * 8 - 1;

	if (n == 0)
	{
		putchar ('0');
		return;
	}

	while ((n & (1UL << rep)) == 0)
	{
		rep--;
	}

	for (; rep >= 0; rep--)
	{
		putchar((n & (1UL << rep)) ? '1' : '0');
	}
}

