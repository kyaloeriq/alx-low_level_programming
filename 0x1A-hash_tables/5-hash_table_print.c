#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * hash_table_print - prints a hash table
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int j;
	hash_node_t *node;
	int flag = 0;

	if (ht != NULL)
	{
		printf("{");
		for (j = 0; j < ht->size; j++)
		{
			node = ht->array[j];
			while (node != NULL)
			{
				if (flag == 1)
					printf(", ");
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				flag = 1;
			}
		}
		printf("}\n");
	}
}
