#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - adds two numbers
 * @argc: argument count
 * @argv: passed arguments
 * Return: 0 if successful and 1 if not
 */
int main(int argc, char *argv[])
{
	int a, sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (a = 1; a < argc; a++)
	{
		char *num_str = argv[a];
		int num;
		int b = 0;

		while (num_str[b] != '\0')
		{
			if (!isdigit(num_str[b]))
			{
				printf("Error\n");
				return (1);
			}
			b++;
		}
		num = atoi(num_str);
		sum += num;
	}
	printf("%d\n", sum);
	return (0);
}
