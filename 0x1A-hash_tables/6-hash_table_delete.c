#include <stdlib.h>
#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int j;
	hash_node_t *node, *temp;

	if (ht != NULL)
	{
		for (j = 0; j < ht->size; j++)
		{
			node = ht->array[j];
			while (node != NULL)
			{
				temp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = temp;
			}
		}
		free(ht->array);
		free(ht);
	}
}
