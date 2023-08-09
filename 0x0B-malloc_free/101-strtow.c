#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * strtow - splits a string into words
 * @str: string
 * Return: pointer to an array of strings
 */
char **strtow(char *str)
{
	int a, b, word_count, word_index;
	char **word_array, *token;

	word_count = 0;
	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}
	for (a = 0; str[a] != '\0'; a++)
	{

		if (str[a] != ' ' && (a == 0 || str[a - 1] == ' '))
		{
			word_count++;
		}
	}
	word_array  = (char **)malloc((word_count + 1) * sizeof(char *));
	if (word_array == NULL)
	{
		return (NULL);
	}
	word_index = 0;
	token = strtok(str, " ");
	while (token != NULL)
	{
		word_array[word_index] = strdup(token);
		if (word_array[word_index] == NULL)
		{
			for (b = 0; b < word_index; b++)
			{
				free(word_array[b]);
			}
			free(word_array);
			return (NULL);
		}
		word_index++;
		token = strtok(NULL, " ");
	}
	word_array[word_index] = NULL;
	return (word_array);
}
