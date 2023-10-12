#include "lists.h"

/**
 * print_dlistint - Print all elements of a doubly linked list
 * @h: A pointer to the head of the doubly linked list
 * Return: The number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	int count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
