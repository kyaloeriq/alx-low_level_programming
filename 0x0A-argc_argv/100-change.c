#include <stdio.h>
#include <stdlib.h>
/**
 * minimumCoins - prints the minimum number of coins
 * main - calls minimumCoins
 * required to make change
 * @cents: number of coins to give back
 * Return: Error if number of arg passed is not 1
 */
int minimumCoins(int cents)
{
	int coins[] = {25, 10, 5, 2, 1};
	int numCoins = sizeof(coins) / sizeof(coins[0]);

	int a;
	int count = 0;

	for (a = 0; a < numCoins; a++)
	{
		while (cents >= coins[a])
		{
			cents -= coins[a];
			count++;
		}
	}
	return (count);
}
int main(int argc, char *argv[])
{
	int cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
	}
	else
	{
		int minCoins = minimumCoins(cents);

		printf("%d\n", minCoins);
	}
	return (0);
}
