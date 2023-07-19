#include "main.h"
/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void)
{
	int p, q, r;

	for (p = 0; p < 10; p++)
	{
		for (q = 0; q < 10; q++)
		{

			r = q * p;
			if (q == 0)
			{
				_putchar(r + '0');
			}
			if (r < 10 && q != 0)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(r + '0');
			}
			else if (r >= 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar((r / 10) + '0');
				_putchar((r % 10) + '0');
			}
		}
		_putchar('\n');
	}
}

