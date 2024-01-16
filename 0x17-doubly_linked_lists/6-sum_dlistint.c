#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
/**
 * sum_dlistint - returns the sum of all the data (n)
 * @head: pointer to head
 * Return: sum of data
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	/*Loop through the list and add up the values*/
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
