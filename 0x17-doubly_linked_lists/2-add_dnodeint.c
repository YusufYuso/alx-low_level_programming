#include "lists.h"

/**
 * add_dnodeint - Add a new node at the beginning of a doubly linked list
 * @head: A pointer to a pointer to the head of the doubly linked list
 * @n: The integer value to store in the new node
 * Return: A pointer to the newly added node, or NULL if it fails
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}
