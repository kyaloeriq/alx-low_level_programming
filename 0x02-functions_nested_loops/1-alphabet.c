#include "main.h"
/**
 * main - prints the alphabet, in lowercase,
 * followed by a new line.
 * Return: 0
 */
int main(void)
{
	char alphabet = 'a';
		while (alphabet <= 'z')
		{
			_putchar(alphabet);
			alphabet++;
		}
		_putchar('\n');
		return (0);
}
