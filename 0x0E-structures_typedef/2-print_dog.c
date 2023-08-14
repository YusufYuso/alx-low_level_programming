#include "dog.h"

/**
 * print_dog - Prints a struct dog.
 * @d: The struct dog to be printed.
 */
void print_dog(struct dog *d)
{
	if (d)
	{
		printf("Name: %s\n", d->name ? d->name : "(nil)");
		if (d->age < 0)
			printf("Age: (nil)\n");
		else
			printf("Age: %f\n", d->age);
		printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
	}
}
