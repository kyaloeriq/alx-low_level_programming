#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"
/**
 *key_index - gives you the index of a key
 *@key: key
 *@size: size of the array of the hash table
 *Return:  index at which the key/value pair should be stored 
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
        unsigned long int hash;
        int c;

        hash = 5381;
        while ((c = *key++))
        {
                hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        }
	/*Reduce the hash value to fit within the table size*/
	hash %= size;

        return (hash);
}
