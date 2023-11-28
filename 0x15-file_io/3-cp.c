#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"
/**
 * close_and_exit - Closes file descriptor
 * @fd: File descriptor to close
 * @code_exit: Exit code incase of error
 */
void close_and_exit(int fd, int code_exit, const char *file_name)
{
	if (close(fd) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(code_exit);
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
	size_t bytes_read;

	if (argc != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from = open(file_from, O_RDONLY);
	if (from == -1)
	{
		dprintf(2, "Error: Can't read from %s\n", file_from);
		exit(98);
	}
	/*O_CREAT with mode 0644 and O_TRUNC to create/truncate the file*/
	to = open(file_to, O_WRONLY | O_CREAT, O_TRUNC, 0644);
	if (to == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", file_to);
		close_and_exit(from, 99, file_from);
	}
	while ((bytes_read = read(from, buffer, sizeof(buffer))) > 0)
	{
		if (write(to, buffer, bytes_read) != bytes_read)
		{
			dprintf(2, "Error: Can't write to %s\n", file_to);
			close_and_exit(from, 99, file_from);
		}
	}
	if (close(to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", to);
		exit(100);
	}
	close_and_exit(from, 0, file_from);
}
