#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"
/**
 * main - check the code
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char operator;
	int num1, num2;
	int result;
	int (*calc_func)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	operator = argv[2][0];
	if (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%')
	{
		printf("Error\n");
		exit(99);
	}
	if ((operator == '/' || operator == '%') && atoi(argv[3]) == 0)
	{
		printf("Error\n");
		exit(100);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	calc_func = get_op_func(&operator);
	if (calc_func == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	result = calc_func(num1, num2);
	printf("%d\n", result);
	return (0);
}

