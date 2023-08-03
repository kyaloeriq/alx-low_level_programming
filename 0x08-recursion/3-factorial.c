#include "main.h"
#include <stdio.h>
/**
 * factorial - returns the factorial of a given number
 * @n: input
 * Return: 0
 */
int factorial(int n)
{
	n = n * (n - 1);

	if (n < 0)
	{
		return (-1);
	}
	else
	{
		printf("%d", n);
		return (0);
	}
}
