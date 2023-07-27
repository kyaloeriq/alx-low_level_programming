#include "main.h"
/**
 * reverse_array - reverses the content of an array of integers
 * @n: number of elements of the array
 * @a: array
 * Return: 0
 */
void reverse_array(int *a, int n)
{
	int i, t;

	for (i = 0; i < n--; i++)
	{
		t = a[i];
		a[i] = a[n];
		a[n] = t;
	}
}

