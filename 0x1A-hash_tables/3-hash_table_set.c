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
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
{
	unsigned long int hash = 5381; // Initialize hash to some value
        int c;

        // Calculate the hash value for the given key
        while ((c = *key++)) {
                hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        }
	key->value = value;
	if (key != str[])
		value == ht;
	else
		return (NULL);
}
