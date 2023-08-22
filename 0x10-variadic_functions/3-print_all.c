#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of all types of args passed
 * Return: void
 */
void print_all(const char * const format, ...)
{
	int a;
	char *str;
	va_list args;

	a = 0;

	va_start(args, format);
	while (format && format[a])
	{
		switch (format[a])
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;

			case 'i':
				printf("%d", va_arg(args, int));
				break;

			case 'f':
				printf("%f", va_arg(args, double));
				break;

			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					printf("(nil)");
				else
					printf("%s", str);
				break;
			default:
				break;
		}
		if ((format[a] == 'c' || format[a] == 'i' || format[a] == 'f' || format[a] == 's') && format[a + 1])
			printf(", ");
		a++;
	}
	va_end(args);
	putchar('\n');
}
