#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * assign a random number to the variable n each time it is executed
 * variable will store a different number every time program is run
 * Return: Always (Success)
 */

int main(void)
{
	int n;
	
	srand(time(0));
	n = rand() - RAND_MAX / 2;

	/* print whether the number stored in variable n is positive or negative*/

	if (n > 0)
	{
		printf("%d is positive \n", n);
	}
	else if (n < 0)
	{
		printf("%d is negative \n", n);
	}
	else 
	{
		printf("%d is zero \n", n);
	}
	return (0);
}
