#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list
 * @head: A pointer to the head of the doubly linked list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *node;

	while (head)
	{
		node = head;
		head = head->next;
		free(node);
	}
}
