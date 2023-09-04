#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * read_textfile - reads text file,prints it to the POSIX standard output
 * @filename: name of file
 * @letters: no. of letters to read and print
 * Return: no. of letters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buff;
	size_t read_bytes;
	ssize_t written_bytes;

	if (filename == NULL || letters == 0)
		return (0);
	file = fopen(filename, "r");
	if (file == NULL)
		return (0);
	buff = malloc(letters);

	if (buff == NULL)
	{
		fclose(file);
		return (0);
	}
	read_bytes = fread(buff, 1, letters, file);
	fclose(file);

	if (read_bytes == 0)
	{
		free(buff);
		return (0);
	}
	written_bytes = write(STDOUT_FILENO, buff, read_bytes);

	free(buff);
	if (written_bytes < 0)
		return (0);
	return (written_bytes);
}
