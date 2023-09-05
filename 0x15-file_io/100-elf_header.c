#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"
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
	ELFhdr a;

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
	fread(&a, sizeof(a), 1, efile);
	if (a.e_ident[0] != 0x7f || a.e_ident[1] != 'E' || a.e_ident[2] != 'L' || a.e_ident[3] != 'F')
	{
		printf("This is not an ELF file.\n");
		fclose(efile);
		exit(98);
	}

	printf("Magic: %02x %02x %02x %02x\n", a.e_ident[0], a.e_ident[1], a.e_ident[2], a.e_ident[3]);
	printf("Class: %d-bit\n", (a.e_ident[4] == 1) ? 32 : 64);
	printf("Data: %s-endian\n", (a.e_ident[5] == 1) ? "Little" : "Big");
	printf("Version: %d\n", a.e_ident[6]);
	printf("OS/ABI: %d\n", a.e_ident[7]);
	printf("ABI Version: %d\n", a.e_ident[8]);
	printf("Type: %d\n", a.e_type);
	printf("Entry point address: 0x%x\n", a.e_entry);

	fclose(efile);
	return (0);
}

