#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * main - copies the content of a file to another file
 * @argc: 1st argument
 * @argv: 2nd argument
 * Return: 0
 */
int main(int argc, char *argv[])
{
	const char *file_from = argv[1];
	const char *file_to = argv[2];
	FILE *from, *to;
	char buffer[1024];
	size_t read_bytes;

	if (argc != 3)
	{
		perror("Usage: cp file_from file_to");
		exit(97);
	}
	from = fopen(file_from, "rb");
	if (from == NULL)
	{
		perror("Can't read from file_from");
		exit(98);
	}

	to = fopen(file_to, "wb");
	if (to == NULL)
	{
		perror("Can't write to file_to");
		exit(99);
	}
	while ((read_bytes = fread(buffer, 1, sizeof(buffer), from)) > 0)
	{
		if (fwrite(buffer, 1, read_bytes, to) != read_bytes)
		{
			perror("Can't write to file_to");
			fclose(from);
			fclose(to);
			exit(99);
		}
	}
	fclose(from);
	fclose(to);
	return (0);
}
