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
	unsigned int a;
	const char *fmt_ptr;
	int separator;

	separator = 0;
	fmt_ptr = format;
	a = 0;
	va_start(args, format);
	while (format && fmt_ptr[a])
	{
	if (fmt_ptr[a] == 'c' || fmt_ptr[a] == 'i' || fmt_ptr[a] == 'f' || fmt_ptr[a] == 's')
		{
		if (separator)
			printf(", ");
		separator = 1;
		if (fmt_ptr[a] == 'c')
			printf("%c", va_arg(args, int));
		else if (fmt_ptr[a] == 'i')
			printf("%d", va_arg(args, int));
		else if (fmt_ptr[a] == 'f')
			printf("%f", va_arg(args, double));
		else if (fmt_ptr[a] == 's')
		{

			char *str = va_arg(args, char *);

			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
		}
		}
		a++;
	}
	va_end(args);
	putchar('\n');
}
