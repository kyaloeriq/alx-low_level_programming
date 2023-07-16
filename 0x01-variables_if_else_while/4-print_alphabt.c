#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - prints the alphabet in lowercase except q and e,
 * followed by a new line
 * Return: Always (Success)
 */
int main(void)
{
	char alphabet = 'a';

	while (alphabet <= 'z' && alphabet != 'q' && alphabet != 'e')
	{
	putchar(alphabet);
	alphabet++;
	}
	putchar('\n');
	return (0);
}

