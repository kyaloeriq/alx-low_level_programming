#include "main.h"
#include <stdio.h>
/**
 * main - prints the number of arguments passed
 * followed by a new line
 * @argc: number of arguments passed
 * @argv: array of strings containing arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	printf("%d\n", argc - 1);
	return (0);
}
