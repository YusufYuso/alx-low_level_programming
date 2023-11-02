#include "hash_tables.h"

/**
 * hash_table_print - Prints the contents of a hash table.
 * @ht: The hash table to be printed.
 *
 * Return: No return value (void).
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index;
	int printed = 0;
	hash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		current = ht->array[index];
		while (current != NULL)
		{
			if (printed)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			printed = 1;
			current = current->next;
		}
	}
	printf("}\n");
}
