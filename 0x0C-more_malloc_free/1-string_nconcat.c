#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * string_nconcat - concatenates two strings
 * @s1: 1st string
 * @s2: 2nd string
 * @n: bytes of s2
 * Return: pointer  to a newly allocated space in memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	size_t len1, len2, concat_len;
	size_t a, b;

	len1 = strlen(s1);
	len2 = strlen(s2);
	concat_len = len1 + (n < len2 ? n : len2);
	concat = (char *)malloc((concat_len + 1) * sizeof(char));
	if (concat == NULL)
	{
		return (NULL);
	}
	for (a = 0; a < len1; a++)
	{
		concat[a] = s1[a];
	}
	for (b = 0; b < n && s2[b] != '\0'; b++, a++)
	{
		concat[a] = s2[b];
	}
	concat[a] = '\0';
	return (concat);
}
