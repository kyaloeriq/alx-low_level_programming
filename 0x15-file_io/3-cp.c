#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void close_and_exit(int fd, int exit_code) 
{
	if (close(fd) == -1) 
	{
		fprintf(stderr, "Error: Can't close fd %d\n", fd);
		perror("close");
		exit(exit_code);
	}
}
int main(int argc, char *argv[])
{
	const char *file_from = argv[1];
	const char *file_to = argv[2];
	FILE *from, *to;
	char buffer[1024];
	size_t read_bytes;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	from = fopen(file_from, "rb");
	if (from == NULL)
	{
		perror("Error: Can't read from file_from\n");
		exit(98);
	}
	to = fopen(file_to, "wb");
	if (to == NULL)
	{
		perror("Error: Can't write to file_to\n");
		close_and_exit(fileno(from), 100);
		exit(99);
	}
	while ((read_bytes = fread(buffer, 1, sizeof(buffer), from)) > 0)
	{
		if (fwrite(buffer, 1, read_bytes, to) != read_bytes)
		{
			perror("Error: Can't write to file_to\n");
			close_and_exit(fileno(from), 100);
			close_and_exit(fileno(to), 100);
			exit(100);
		}
	}
	close_and_exit(fileno(from), 100);
	close_and_exit(fileno(to), 100);
	return (0);
}
