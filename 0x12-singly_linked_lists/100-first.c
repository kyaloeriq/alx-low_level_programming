#include <stdio.h>
#include "lists.h"
/**
 * print_str - prints string before the main function is executed
 * Return: str
 */
void print_str(void) __attribute((constructor));
void print_str(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
