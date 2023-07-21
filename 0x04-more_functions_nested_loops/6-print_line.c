#include "main.h"
/**
 * print_line - draws a straight line in the terminal
 * @n: number of times the character _ should be printed
 * Return: 0
 */
void print_line(int n)
{
	for (n = 0; n < 10; n++)
	{
		if (n < 0)
		{
			_putchar('\n');
		}
	_putchar('_');
	}
	_putchar('\n');
}
