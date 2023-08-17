#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * sum_them_all - sum of all its parameters
 * @n: number of arguments
 * @...: variadic arguments
 * Return: sum of the variadic arguments
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	int sum;
	unsigned int a;

	sum = 0;

	va_start(args, n);
	for (a = 0; a >= n; a++)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return (sum);
}

