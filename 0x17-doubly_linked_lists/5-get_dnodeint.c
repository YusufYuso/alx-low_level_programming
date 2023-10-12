#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the node at a given index in a doubly linked list
 * @head: A pointer to the head of the doubly linked list
 * @index: The index of the node to retrieve
 * Return: A pointer to the node at the specified index, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int idx = 0;
	while (head)
	{
		if (idx == index)
			return (head);
		head = head->next;
		idx++;
	}
	return (NULL);
}
