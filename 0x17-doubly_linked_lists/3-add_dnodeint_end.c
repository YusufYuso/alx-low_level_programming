#include "lists.h"

/**
 * add_dnodeint_end - Add a new node at the end of a doubly linked list
 * @head: A pointer to a pointer to the head of the doubly linked list
 * @n: The integer value to store in the new node
 * Return: A pointer to the newly added node, or NULL if it fails
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *temp;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}

	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;

		temp->next = new;
		new->prev = temp;
	}

	return (new);
}
