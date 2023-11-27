#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * read_textfile - reads a textfile
 * @filename: name of file
 * @letters: number of letters to be read and printed
 * Return: number of letters it could read and print or 0 incase of error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buff;
	ssize_t read_cnt, write_cnt;

	if (filename == NULL)
	{
		return (0);
	}
	file = fopen(filename, "r");
	if (file == NULL)
	{
		return (0);
	}
	buff = malloc(letters);
	if (buff == NULL)
	{
		fclose(file);
		return (0);
	}
	read_cnt = fread(buff, 1, letters, file);
	if (read_cnt == -1)
	{
		fclose(file);
		free(buff);
		return (0);
	}
	write_cnt = write(STDOUT_FILENO, buff, read_cnt);
	if (write_cnt == -1)
	{
		fclose(file);
		free(buff);
		return (0);
	}
	fclose(file);
	free(buff);
	return (write_cnt);
}
