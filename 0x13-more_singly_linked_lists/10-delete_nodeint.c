#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given
 *                           index of a listint_t list.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * @index: The index of the node to be deleted - indices start at 0.
 *
 * Return: On success - 1.
 *         On failure - -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *node = *head;
	unsigned int i;

	if (node == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(node);
		return (1);
	}
	for (i = 0; i < (index - 1); i++)
	{
		if (node->next == NULL)
			return (-1);

		node = node->next;
	}
	temp = node->next;
	node->next = temp->next;
	free(temp);
	return (1);
}
