#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "main.h"
/**
 * close_and_exit - Closes a file descriptor
 * @fd: File descriptor to close
 * @exit_code: Exit code to use if an error occurs
 */
void close_and_exit(int fd, int exit_code)
{
	if (close(fd) == -1)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", fd);
		exit(exit_code);
	}
}
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
	struct stat st;

	if (argc != 3)
	{
		perror("Usage: cp file_from file_to\n");
		exit(97);
	}
	from = fopen(file_from, "rb");
	if (from == NULL)
	{
		fprintf(stderr, "Can't read from %s\n", file_from);
		exit(98);
	}
	if (stat(file_to, &st) == -1)
	{
		perror("Error getting file information");
		fclose(from);
		exit(98);
	}
	to = fopen(file_to, "wb");
	if (to == NULL)
	{
		fprintf(stderr, "Can't write to %s\n", file_to);
		fclose(from);
		exit(99);
	}
	if (st.st_mode & S_IRUSR)
	{
		if (chmod(file_to, st.st_mode) == -1)
		{
			perror("Error setting file permissions");
			close_and_exit(fileno(from), 99);
			close_and_exit(fileno(to), 99);
		}
	}
	if (truncate(file_to, 0) == -1)
	{
		perror("Error truncating file");
		close_and_exit(fileno(from), 99);
		close_and_exit(fileno(to), 99);
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
	close_and_exit(fileno(from), 100);
	close_and_exit(fileno(to), 100);
	return (0);
}
