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
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *temp = NULL;

	if (*head == NULL || (*head)->next == NULL)
	{
		return (*head);
	}

	while (current != NULL)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}

	*head = prev;
	return (*head);
}
