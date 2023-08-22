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
	char c;
	char *str;
	int num;
	double num1;
	va_list args;

	a = 0;

	va_start(args, format);

	while (format && format[a])
	{
		valid_type = 1;

		if (format[a] == 'c')
		{
			c = va_arg(args, int);
			printf("%c", c);
		}
		else if (format[a] == 'i')
		{
			num = va_arg(args, int);
			printf("%d", num);
		}
		else if (format[a] == 'f')
		{
			num1 = va_arg(args, double);
			printf("%f", num1);
		}
		else if (format[a] == 's')
		{
			str = va_arg(args, char *);
			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
		}
		else
		{
			valid_type = 0;
		}
		if (valid_type && format[a + 1])
			printf(", ");
		a++;
		while (format[a] && format[a] != 'c' && format[a] != 'i' && format[a] != 'f' && format[a] != 's')
		{
			a++;
		}
	}
	va_end(args);
	putchar('\n');
}
