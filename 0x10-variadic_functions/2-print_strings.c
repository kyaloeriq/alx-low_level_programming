#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_strings - function that prints strings
 * @n: numbers of strings
 * @separator: string to be printed btwn strings
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int a;

	va_start(args, n);
	for (a = 0; a < n; a++)
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", str);
		}
		if (separator != NULL && a < n - 1)
		{
			printf("%s", separator);
		}
	}
	va_end(args);
	putchar('\n');
}

