#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * add_dnodeint -  adds a new node at the beginning
 * @head: pointer to head
 * @n: value to be assigned to the new node
 * Return: pointer to the new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = (*head);
	new_node->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}
