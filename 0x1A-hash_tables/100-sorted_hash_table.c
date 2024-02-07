#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 * shash_table_create - creates a hash table
 * @size: size of hash table
 * Return: pointer to hash table, otherwise NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
        shash_table_t *shash_table = NULL;

        if (size == 0)
                return (NULL);
        shash_table = malloc(sizeof(shash_table_t));
        if (shash_table == NULL)
                return (NULL);

        shash_table->size = size;
        shash_table->array = malloc(sizeof(shash_node_t *) * size);
        if (shash_table->array == NULL)
        {
                free(shash_table);
                return (NULL);
        }

        return (shash_table);
}
