#include <stdio.h>
/**
 * main - prints the number of arguments passed
 * followed by a new line
 * @argc: number of arguments passed
 * @argv: arrays of strings containing argumnts
 * Return: 0
 */
int main(int argc, char *argv[])
{
	(void)argv;

	printf("%d\n", argc - 1);
	return (0);
}
