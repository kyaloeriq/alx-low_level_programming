#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
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
	int b;

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

	printf("ELF Header:\n");
	printf("Magic:	");
	for (b = 0; b < 16; b++)
	{
		printf("%02x ", a.e_ident[b]);
	}
	printf("\n");
	printf(" Class:	ELF%d\n", (a.e_ident[4] == 1) ? 32 : 64);
	printf(" Data:	%s's complement, %s-endian\n", (a.e_ident[5] == 1) ? "2" : "1", (a.e_ident[6] == 1) ? "Little" : "Big");
	printf(" Version:	%d (current)\n", a.e_ident[6]);
	printf(" OS/ABI:	%s\n", a.e_ident[7] == 0 ? "UNIX - System V" : "UNKNOWN");
	printf(" ABI Version:	%d\n", a.e_ident[8]);
	printf(" Type: %s\n", (a.e_type == 2) ? "EXEC (Executable file)" : "UNKNOWN");
	printf(" Entry point address:	0x%x\n", a.e_entry);

	fclose(efile);
	return (0);
}
