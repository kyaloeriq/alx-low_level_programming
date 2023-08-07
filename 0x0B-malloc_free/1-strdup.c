#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * _strdup - returns a pointer to a new allocated space in memory
 * @str: string
 * Return: pointer to a new string, duplicate of the string str
 */
char *_strdup(char *str)
{
	size_t len;
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}
	len = strlen(str);
	duplicate = (char *)malloc((len + 1) * sizeof(char));
	if (duplicate == NULL)
	{
		return (NULL);
	}
	strcpy(duplicate, str);
	return (duplicate);
}

