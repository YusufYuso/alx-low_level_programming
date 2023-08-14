#include "dog.h"

/**
 * free_dog - Frees dogs.
 * @d: The dog to be freed.
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
