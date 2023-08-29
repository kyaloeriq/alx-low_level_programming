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
	const listint_t *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		printf("[0x%lx]%d\n", (unsigned long)slow, slow->n);
		count++;

		if (slow == fast)
		{
			exit(98);
		}
	}
	return (count);
}
