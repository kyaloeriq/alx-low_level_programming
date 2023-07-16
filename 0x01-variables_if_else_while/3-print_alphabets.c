#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - prints the alphabet in lowercase, and then in uppercase,
 * followed by a new line
 * Return: Always (Success)
 */
int main(void)
{
	char alphabet = 'a';
	char ALPHABET = 'A';

	while (alphabet <= 'z')
	{
	putchar(alphabet);
	alphabet++;
	}
	while (ALPHABET <= 'Z')
	{
	putchar(ALPHABET);
	ALPHABET++;
	}
	putchar('\n');
	return (0);
}
