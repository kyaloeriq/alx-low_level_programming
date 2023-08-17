#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the opcodes of its own main function
 * @argc: number of command-line arguments
 * @argv: array of command line arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int number_of_bytes;
	unsigned char *main_ptr;
	int a;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	number_of_bytes = atoi(argv[1]);

	if (number_of_bytes <= 0)
	{
		printf("Error\n");
		return (2);
	}

	main_ptr = (unsigned char *)main;

	for (a = 0; a < number_of_bytes; a++)
	{
		printf("%02x ", main_ptr[a]);
	}
	printf("\n");
	return (0);
}

