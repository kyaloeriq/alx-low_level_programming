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

	if (calc_func == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	if (num2 == 0 && (argv[2][0] == '/' || argv[2][0] == '%'))
	{
		printf("Error\n");
		exit(100);
	}

	result = calc_func(num1, num2);
	printf("%d\n", result);
	return (0);
}

