#include "main.h"
/**
 * print_line - draws a straight line in the terminal
 * @n: number of times the character _ should be printed
 * Return: 0
 */
void print_line(int n)
{
	int a;

	for (a = 0; a < 10; a++)
	{
		if (n <= 0)
		{
			_putchar('\n');
		}
		else
		_putchar('_');
	}
	_putchar('\n');
}
