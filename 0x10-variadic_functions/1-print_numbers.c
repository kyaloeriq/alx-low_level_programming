#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_numbers - prints numbers followed by a new line
 * @n: number of arguments
 * @separator: string to be printed
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int a;

	va_start(args, n);
	for (a = 0; a < n; a++)
	{
		printf("%d", va_arg(args, int));

		if (separator != NULL && a < n - 1)
			printf("%s", separator);
	}
	va_end(args);
	putchar('\n');
}
