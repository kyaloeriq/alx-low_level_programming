#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
/**
 * create_file -  creates a file
 * @filename: name of file
 * @text_content: string to write on file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file;
	ssize_t bytes = 0;

	if (filename == NULL)
		return (-1);
	file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[bytes] != '\0')
			bytes++;
		if (write(file, text_content, bytes) == -1)
		{
			close(file);
			return (-1);
		}
	}
		close(file);
		return (1);
}
