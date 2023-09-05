#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - copies the content of a file to another file
 * @argc: first param
 * @argv: second param
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *original = argv[1];
	char *copy = argv[2];
	FILE *src;
	FILE *dest;
	char buf[1024];
	size_t bytes;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <source_file><destination_file>\n", argv[0]);
		return (-1);
	}
	src = fopen(original, "rb");
	if (src == NULL)
	{
		exit(98);
		perror("Error: Can't read from file original\n");
	}
	dest = fopen(copy, "wb");
	if (dest == NULL)
	{
		exit(99);
		perror("Error: Can't write to copy\n");
		fclose(src);
	}
	while ((bytes = fread(buf, 1, sizeof(buf), src)) > 0)
	{
		if (fwrite(buf, 1, bytes, dest) != bytes)
		{
			perror("fwrite");
			fclose(src);
			fclose(dest);
		}
	}
	fclose(src);
	fclose(dest);
	return (0);
}

