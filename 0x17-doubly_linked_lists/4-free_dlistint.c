#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to head
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *node = head;
	dlistint_t *next_node;

	while (node != NULL)
	{
		next_node = node->next; /*Store the next node before freeing the current*/
		free(node);
		node = next_node; /*Move to the next node*/
	}
}
