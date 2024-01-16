#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
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
