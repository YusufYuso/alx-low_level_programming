#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t list.
 * @head: A pointer to the address of
 *        the head of the list_t list.
 *
 * Return: A pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *temp = NULL, *n = NULL;

	if (head == NULL || *head == NULL)
		return (NULL);
	temp = *head;
	*head = NULL;
	while (temp)
	{
		n = temp->next;
		temp->next = *head;
		*head = temp;
		temp = n;
	}
	return (*head);
}
