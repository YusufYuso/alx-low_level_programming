#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to get the length of.
 *
 * Return: The length of @s.
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0';)
		++i;
	return (i);
}
