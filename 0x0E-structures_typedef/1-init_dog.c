#include <stddef.h>
#include "dog.h"
/**
 * init_dog - function that initialize a variable of type struct dog
 * @d: 1st param
 * @name: 2nd param
 * @age: 3rd param
 * @owner: 4th param
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		return;
	}
	d->name = name;
	d->age = age;
	d->owner = owner;
}
