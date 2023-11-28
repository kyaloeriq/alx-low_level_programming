#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
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
		dprintf(2, "Error: Can't close fd %d\n", fd);
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
	int from, to;
	char buffer[1024];
	size_t read_bytes;
	struct stat st;

	if (argc != 3)
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	from = open(file_from, O_RDONLY);
	if (from == -1)
	{
		dprintf(2, "Error: Can't read from %s\n", file_from);
		exit(98);
	}
	if (fstat(from, &st) == -1)
	{
		close_and_exit(from, 98);
	}
	to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, st.st_mode);
	if (to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", file_to);
		close_and_exit(from, 99);
	}
	while ((read_bytes = read(from, buffer, sizeof(buffer))) > 0)
	{
		if (write(to, buffer, read_bytes) != read_bytes)
		{
			dprintf(2, "Error: Can't write to %s\n", file_to);
			close_and_exit(from, 99);
		}
	}
	if (close(to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", to);
		exit(100);
	}
	close_and_exit(from, 0);
}
