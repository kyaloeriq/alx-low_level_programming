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
	va_list args;
	char *separator;
	int a;

	separator = "";
	a = 0;
	va_start(args, format);
	while (format && format[a])
	{
		while (format[a] != 'c' && format[a] != 'i' && format[a] != 'f' && format[a] != 's' && format[a])
		{
			a++;
		}
		if (!format[a])
			break;
		if (format[a] == 'c')
		{
			printf("%s%c", separator, va_arg(args, int));
		}
		if (format[a] == 'i')
		{
			printf("%s%d", separator, va_arg(args, int));
		}
		if (format[a] == 'f')
		{
			printf("%s%f", separator, va_arg(args, double));
		}
		if (format[a] == 's')
		{

			char *str = va_arg(args, char *);

			if (str == NULL)
				printf("(%s(nil)", separator);
			else
				printf("%s%s", separator, str);
		}
		separator = ", ";
		a++;
	}
	va_end(args);
	putchar('\n');
}
