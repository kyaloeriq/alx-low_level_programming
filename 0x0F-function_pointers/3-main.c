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
	char op;
	int num1, num2;
	int result;
	int (*calc_func)(int, int);

	op = argv[2][0];
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	calc_func = get_op_func(&op);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
	{
		printf("Error\n");
		return (99);
	}
	if ((num2 == 0) && (op  == '/' || op  == '%'))
	{
		printf("Error\n");
		exit(100);
	}
	result = calc_func(num1, num2);
	printf("%d\n", result);
	return (0);
}
