#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "main.h"
/**
 * read_elf_header - readads ELF header from a file
 * @filename: name of file
 * Return: 0
 */
int read_elf_header(const char *filename, struct elf_header *elf)
{
	FILE *file = fopen(filename, "rb");
	size_t read_num;

	if (!file)
	{
		fprintf(stderr, "Couldn't open file %s\n", filename);
		return (1);
	}
	read_num = fread(elf, sizeof(struct elf_header), 1, file);
	fclose(file);
	if (read_num != 1)
	{
		fprintf(stderr, "Error reading ELF header from %s\n", filename);
		return (1);
	}
	return (0);
}
/**
 * print_elf_header - displays ELF header information
 * @elf: pointer to elf_header structure
 */
void print_elf_header(const struct elf_header *elf)
{
	printf("ELF Header:\n");
	printf("	Magic:	0x%08X\n", elf->magic);
	printf("	Class:	%d-bit\n", elf->class == 1 ? 32 : 64);
	printf("	Data:	%s\n", elf->data == 1 ? "2's complement, little endian" : "2's complement, big endian");
	printf("	Version: %d (current)\n", elf->version);
	printf("	OS/ABI:	%d\n", elf->OS_ABI);
	printf("	ABI Version:	%d\n", elf->ABIVersion);
	printf("	Type:	0x%04X (EXEC)\n", elf->type);
	printf("	Entry point address:	0x%016lX\n", elf->entrypointaddress);
}
/**
 * main - displays information in the ELF header at start of an ELF file
 * Return: 0
 */
int main(int argc, char *argv[])
{
	struct elf_header elf_file;

	if (argc != 2)
	{
		fprintf(stderr, "Insufficient Arguments\n");
		exit(98);
	}
	/*Read ELF header from file*/
	if (!read_elf_header(argv[1], &elf_file))
	{
		exit(98);
	}
	/*Check if file is an ELF*/
	if (elf_file.magic != 0X464C457F)
	{
		fprintf(stderr, "Not an ELF file\n");
		exit(98);
	}
	print_elf_header(&elf_file);
	return (0);
}
