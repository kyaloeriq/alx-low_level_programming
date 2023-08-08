#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * strtow - splits a string into words
 * @str: string
 * Return: pointer to an array of strings
 */
bool is_whitespace(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}
int count_words(const char *str)
{
	int count = 0;
	bool in_word = false;

	while (*str)
	{
		if (is_whitespace(*str))
		{
			in_word = false;
		}
		else if (!in_word)
		{
			in_word = true;
			count++;
		}
		str++;
		}
	return (count);
}
char **strtow(char *str)
{
	int num_words;
        int a;
        int current_word = 0;
        char *word_start;
        bool in_word = false;
        int word_length;
        char **word_array;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}

       	num_words = count_words(str);
	word_array = ((char **)malloc((num_words + 1) * sizeof(char *)));
	if (word_array == NULL)
	{
		return (NULL);
	}
	while (*str) 
	{
		if (!is_whitespace(*str))
		{
			if (!in_word)
			{
			in_word = true;
			word_start = str;
			}
			else if (in_word)
			{
				int word_length = str - word_start;
				word_array[current_word] = (char *)malloc((word_length + 1) * sizeof(char));
				if (word_array[current_word] == NULL)
				{
					for (a = 0; a < current_word; a++)
					{
						free(word_array[a]);
					}
					free(word_array);
					return NULL;
				}
			strncpy(word_array[current_word], word_start, word_length);
			word_array[current_word][word_length] = '\0';
			current_word++;
			in_word = false;
			}
		}
		str++;
	}
	if (in_word)
	{
       	word_length = str - word_start;
	word_array[current_word] = (char *)malloc((word_length + 1) * sizeof(char));
	if (word_array[current_word] == NULL)
	{
		for (a = 0; a < current_word; a++) 
		{
                free(word_array);
		}
            free(word_array);
            return NULL;
        }
	strncpy(word_array[current_word], word_start, word_length);
	word_array[current_word][word_length] = '\0';
	current_word++;
	}
	word_array[current_word] = NULL;
	return (word_array);
}

