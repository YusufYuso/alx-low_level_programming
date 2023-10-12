#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a given index in a DLL
 * @head: A pointer to a pointer to the head of the doubly linked list
 * @index: The index of the node to delete
 * Return: 1 if the node was successfully deleted, -1 if it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node = *head;
	unsigned int i = 0;

	if (!*head)
		return (-1);

	if (index == 0)
	{
		*head = node->next;
		if (*head)
			(*head)->prev = NULL;
		free(node);
		return (1);
	}

	while (node && i < index)
	{
		node = node->next;
		i++;
	}

	if (!node)
		return (-1);

	node->prev->next = node->next;

	if (node->next)
		node->next->prev = node->prev;

	free(node);
	return (1);
}
