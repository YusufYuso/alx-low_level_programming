#include "lists.h"
#include<string.h>

/**
 * add_node - Adds a new node at the beginning
 *            of a list_t list.
 * @head: A pointer to the head of the list_t list.
 * @str: The string to be added to the list_t list.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new element.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new = malloc(sizeof(list_t));
	if (new == NULL || str == NULL)
	{
		free(new);
		return(NULL);
	}	
	else
	{
		new->str = strdup(str);
		new->next = *head;
		new->len = strlen(str);
		*head = new;
	}
	return (*head);
}
