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

        if (argv < 1)
        {
                printf("Error\n");
                return (1);
        }
	if (argv != int)
	{
		printf("Error\n");
		return (1);
	}

        a = atoi(argv[1]);
        b = atoi(argv[2]);

        sum = a + b;
        printf("%d\n", sum);
        return (0);
}
