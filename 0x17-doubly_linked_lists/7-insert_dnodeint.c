#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given index in a DLL
 * @h: A pointer to a pointer to the head of the doubly linked list
 * @idx: The index at which the new node should be inserted
 * @n: The integer value to store in the new node
 * Return: A pointer to the newly inserted node, or NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new = NULL, *current = *h;
	unsigned int i = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));
	while (current && i < idx - 1)
	{
		current = current->next;
		i++;
	}
	if (!current)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = current;
	new->next = current->next;
	if (current->next)
		current->next->prev = new;
	current->next = new;
	return (new);
}
