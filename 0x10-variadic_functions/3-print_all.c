#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

typedef struct
{
	char format;
	void (*print_function)(va_list);
} FormatHandler;

void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}
void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}
void print_string(va_list args)
{
	char *str = va_arg(args, char *);
	if (str == NULL)
		printf("(nil)");
	else
		printf("%s", str);
}
FormatHandler handlers[] = {
	{'c', print_char},
	{'i', print_int},
	{'f', print_float},
	{'s', print_string},
};

/**
 * print_all - prints anything
 * @format: list of all types of args passed
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	size_t b;
	char current_format;
	size_t num_handlers;
	int format_index;

	format_index = 0;
	va_start(args, format);

	num_handlers = sizeof(handlers) / sizeof(handlers[0]);
	while (format && format[format_index])
	{
		current_format = format[format_index];
		b = 0;

		while (b < num_handlers && handlers[b].format != current_format)
		{
			b++;
		}
		if (b < num_handlers)
		{
			handlers[b].print_function(args);
			if (format[format_index + 1] != '\0')
			{
				printf(", ");
			}
		}
		format_index++;
	}
	va_end(args);
	putchar('\n');
}
