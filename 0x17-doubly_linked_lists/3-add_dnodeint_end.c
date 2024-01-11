#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to head
 * @n: value to be assigned to the new node
 * Return: pointer to new node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *last_node, *temp;

	last_node = malloc(sizeof(dlistint_t));
	if (last_node == NULL)
	{
		return (NULL);
	}

	last_node->n = n;
	last_node->next = NULL;

	if (*head == NULL)
	{
		last_node->prev = NULL;
		*head = last_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = last_node;
		last_node->prev = temp;
	}
	return (last_node);
}
