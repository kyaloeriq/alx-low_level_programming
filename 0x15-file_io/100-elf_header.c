#include <stdio.h>
#include <stdlib.h>
/**
 * main - displays info. contained in the ELF header
 * at the start of an ELF file
 * @argc: first param
 * @argv: second param
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *efile;
	unsigned char magic[4];

	if (argc != 2)
	{
		fprintf(stderr, "There might be an error\n");
		exit(98);
	}
	efile = fopen(argv[1], "rb");
	if (efile == NULL)
	{
		perror("There might be an error\n");
		exit(98);
	}
	fread(magic, 1, 4, efile);
	if (magic[0] == 0x7f && magic[1] == 'E' && magic[2] == 'L' && magic[3] == 'F')
	{
		printf("This is an ELF file.\n");
	}
	else
	{
		printf("This is not an ELF file.\n");
		fclose(efile);
		exit(98);
	}
	fclose(efile);
	return (0);
}

