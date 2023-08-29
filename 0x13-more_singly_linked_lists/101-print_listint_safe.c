#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to head
 * Return: number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;

	while (current != NULL)
	{
		printf("[0x%lx]%d\n", (unsigned long)current, current->n);
		count++;
		if (current >= current->next)
		{
			exit(98);
		}
		current = current->next;
	}
	return (count);
}
