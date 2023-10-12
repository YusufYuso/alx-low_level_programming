#include "lists.h"

/**
 * dlistint_len - Count the number of elements in a doubly linked list
 * @h: A pointer to the head of the doubly linked list
 * Return: The number of elements in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}

	return (len);
}
