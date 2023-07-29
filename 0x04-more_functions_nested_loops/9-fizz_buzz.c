#include "main.h"
#include <stdio.h>
/**
 * main - prints the numbers from 1 to 100
 * but for multiples of 3 prints Fizz instead of the number
 * and for multiples of 5 prints Buzz
 * Return: 0
 */
int main(void)
{
	int a;

	for (a = 1; a <= 100; a++)
	{
		if (a % 3 == 0)
		{
			printf("Fizz");
		}
		else if (a % 5 == 0)
		{
			printf("Buzz");
		}
		else if (a % 15 == 0)
		{
			printf("FizzBuzz");
		}
		else
		{
			printf("%d", a);
		}
	}
	printf("\n");

	return (0);
}
