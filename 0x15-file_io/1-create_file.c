#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"
/**
 * create_file - creates a file
 * @filename: name of the file
 * @text_content: NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_dscp, write_cnt;

	if (filename == NULL)
	{
		return (-1);
	}
	file_dscp = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (file_dscp == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		write_cnt = write(file_dscp, text_content, strlen(text_content));
		if (write_cnt == -1)
		{
			close(file_dscp);
			return (-1);
		}
	}
	close(file_dscp);
	return (1);
}
