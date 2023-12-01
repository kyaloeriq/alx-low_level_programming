#include <stdio.h>
#include "main.h"
void read_elf_header(struct elf_header *elf)
{
	elf->magic = 1;
	elf->class = 2;
       	elf->data = 3;
       	elf->version = 4;
       	elf->OS_ABI = 5;
       	elf->ABIVersion = 6;
       	elf->type = 7;
       	elf->entrypointaddress = 8; 
}
/**
 * main - displays the information contained in the ELF header at the start of an ELF file
 * Return: 0
 */
int main(void)
{
	struct elf_header elf_file;

	read_elf_header(&elf_file);
	printf ("Magic: %d\n", elf_file.magic);
	printf ("Class: %d\n", elf_file.class);
	printf ("Data: %d\n", elf_file.data);
	printf ("Version: %d\n", elf_file.version);
	printf ("OS_ABI: %d\n", elf_file.OS_ABI);
	printf ("ABI Version: %d\n", elf_file.ABIVersion);
	printf ("Type: %d\n", elf_file.type);
	printf ("Entry point address: %d\n", elf_file.entrypointaddress);
	return (0);
}
