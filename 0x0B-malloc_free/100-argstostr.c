#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * argstostr - concatenates all the arguments of your program
 * @ac: first argument
 * @av: second argument
 * Return: pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	int total_length;
	int a;
	char *result;
	int current_position;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	total_length = 0;

	for (a = 0; a < ac; a++)
	{
		total_length += strlen(av[a]) + 1;
	}

	result = (char *)malloc(total_length * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}
	current_position = 0;

	for (a = 0; a < ac; a++)
	{
		strcpy(result + current_position, av[a]);
		current_position += strlen(av[a]);
		result[current_position++] = '\n';
	}
	result[current_position] = '\0';
	return (result);
}
