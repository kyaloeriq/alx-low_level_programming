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
/**
 * shash_table_set - adds an element to the hash table
 * @ht: hash table you want to add or update the key/value to
 * @key: key
 * @value: value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
        shash_node_t *new_node = NULL;
        shash_node_t *temp;
        unsigned long int index;

        if (ht == NULL || key == NULL || value == NULL)
                return (0);

        index = hash_djb2((const unsigned char *)key) % ht->size;

        /*Check if the key already exists in the hash table*/
        temp = ht->array[index];
        while (temp != NULL)
        {
                if (strcmp(temp->key, key) == 0)
                {
                        free(temp->value);
                        temp->value = strdup(value); /*Update the value*/
                        return (1); }
                temp = temp->next; }
        /*If key doesn't exist, create a new node*/
        new_node = malloc(sizeof(shash_node_t));
        if (new_node == NULL)
                return (0); /*Allocation failed*/
        new_node->key = strdup(key);
        if (new_node->key == NULL)
        {
                free(new_node);
                return (0); /*Allocation failed*/ }
        new_node->value = strdup(value);
        if (new_node->value == NULL)
        {
                free(new_node->key);
                free(new_node);
                return (0); /*Allocation failed*/ }
        /*Insert the new node at the beginning of the linked list at index*/
        new_node->next = ht->array[index];
        ht->array[index] = new_node;
        return (1);
}
/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table you want to look into
 * @key: key you are looking for
 * Return: value associated with the element, NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
        unsigned long int index;
        shash_node_t *node;

        if (ht == NULL || key == NULL || *key == '\0')
                return (NULL);

        index = key_index((const unsigned char *)key, ht->size);
        node = ht->array[index];

        while (node != NULL)
        {
                if (strcmp(node->key, key) == 0)
                        return (node->value);
                node = node->next;
        }
        return (NULL);
}
