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

	printf("%d \n", n);

	/* print whether the number stored in variable n is positive or negative*/

	if (n > 0)
	{
		printf("The number is positive \n");
	}
	else if (n < 0)
	{
		printf("The number is negative \n");
	}
	else 
	{
		printf("The number is zero \n");
	}
	return (0);
}
