#include <stdio.h>
#include <stdlib.h>
/**
 * main - adds two numbers
 * @argc: argument count
 * @argv: passed arguments
 * Return: 0 if successful and 1 if not
 */
int main(int argc, char *argv[])
{
	int a, b, sum;

	if (argc != 3)
	{
		printf("0\n");
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	sum = a + b;

	printf("%d\n", sum);
	return (0);
}
