#include "lists.h"

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new, *current;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	current = *head;
	new->n = n;
	current->prev = new;
	new->next = current;
	new->prev = NULL;
	current = new;

	return (current);
}
