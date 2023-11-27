#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_dscp, append_txt;

	if (filename == NULL)
	{
		return (-1);
	}
	file_dscp = open(filename, O_WRONLY | O_APPEND);/*O_APPEND for append*/
	if (file_dscp == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		append_txt = write(file_dscp, text_content, strlen(text_content));
		if (append_txt == -1)
		{
			close(file_dscp);
			return (-1);
		}
	}
	close(file_dscp);
	return (1);
}
