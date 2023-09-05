#include <stdio.h>
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
		fprintf(stderr, "Usage: cp file_from file_to\n");
		exit(97);
	}
	src = fopen(original, "rb");
	if (src == NULL)
	{	perror("Error: Can't read from file original\n");
		fclose(src);
		exit(98);
	}
	dest = fopen(copy, "wb");
	if (dest == NULL)
	{	perror("Error: Can't write to copy\n");
		fclose(dest);
		exit(99);
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
	if (fclose(src) != 0)
	{	perror("Error: Can't close fd original\n");
		exit(100); }
	if (fclose(dest) != 0)
	{	perror("Error: Can't close fd copy\n");
		exit(100); }
	return (0);
}
