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
		if ((format[a] == 'c' || format[a] == 'i' || format[a] == 'f' || format[a] == 's') && (valid_type == 0))
		{
			if (format[a] == 'c')
			printf("%c", va_arg(args, int));

			else if (format[a] == 'i')
			printf("%d", va_arg(args, int));

			else if (format[a] == 'f')
			printf("%f", va_arg(args, double));

			else if (format[a] == 's')
			{
				str = va_arg(args, char *);
				printf("%s", str ? str : "(nil)");
			}
			if (format[a + 1])
			printf(", ");
		}
		valid_type = (format[a] == 'c' || format[a] == 'i' || format[a] == 'f' || format[a] == 's') ? 0 : 1;
		a++;
	}
	va_end(args);
	putchar('\n');
}
