#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to pointer to the head
 * Return: size of free'd list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current;
	listint_t *next;
	size_t size = 0;

	if (h == NULL || *h == NULL)
		return (0);
	current = *h;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		size++;
	}
	*h = NULL;
	return (size);
}
