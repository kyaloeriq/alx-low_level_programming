#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 *hash_table_set - adds an element to the hash table
 *@ht: hash table you want to add or update the key/value to
 *@key: key
 *@value:  value associated with the key
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node = NULL;
	hash_node_t *temp;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = hash_djb2((const unsigned char *)key) % ht->size;

	/*Check if the key already exists in the hash table*/
	temp = ht->array[index];
	while (temp != NULL) {
		if (strcmp(temp->key, key) == 0) {
			free(temp->value);
			temp->value = strdup(value); /*Update the value*/
			return (1);
		}
		temp = temp->next;
	}
	/*If key doesn't exist, create a new node*/
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0); /*Allocation failed*/
	new_node->key = strdup(key);
	if (new_node->key == NULL) {
		free(new_node);
		return (0); /*Allocation failed*/
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL) {
		free(new_node->key);
		free(new_node);
		return (0); /*Allocation failed*/
	}/*Insert the new node at the beginning of the linked list at index*/
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
