#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: pointer to file to be appended to
 * @text_content: pointer to string to be added
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file;
	ssize_t bytes;

	if (filename != NULL && text_content != NULL)
	{
		file = open(filename, O_WRONLY | O_APPEND);

		if (file == -1)
		{
			return (-1);
		}

		bytes = write(file, text_content, strlen(text_content));
		close(file);

		if (bytes == -1)
		{
			return (-1);
		}
		return (1);
	}
	return (-1);
}
