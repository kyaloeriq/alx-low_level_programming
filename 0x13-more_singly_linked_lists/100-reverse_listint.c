#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to head
 * Return: pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current = *head;
	listint_t *new_head = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		return (*head);
	}

	while (current != NULL)
	{
		listint_t *next = current->next;

		current->next = new_head;
		new_head = current;
		current = next;
	}

	*head = new_head;
	return (*head);
}
