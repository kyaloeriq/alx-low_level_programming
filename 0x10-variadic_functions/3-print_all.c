#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of all types of args passed
 * Return: void
 */
void print_all(const char * const format, ...)
{
	int a;
	int valid_type;
	char *str;
	va_list args;

	a = 0;
	valid_type = 1;

	va_start(args, format);
	while (format && format[a])
	{
		if (format[a] == 'c' && (valid_type = 0) == 0)
			printf("%c", va_arg(args, int));

		if (format[a] == 'i' && (valid_type = 0) == 0)
			printf("%d", va_arg(args, int));

		if (format[a] == 'f' && (valid_type = 0) == 0)
			printf("%f", va_arg(args, double));

		if (format[a] == 's' && (valid_type = 0) == 0)
		{
			str = va_arg(args, char *);
			printf("%s", str ? str : "(nil)");
		}
		if (format[a + 1] && valid_type == 0)
			printf(", ");
		
		valid_type = 1;
		a++;
	}
	va_end(args);
	putchar('\n');
}
