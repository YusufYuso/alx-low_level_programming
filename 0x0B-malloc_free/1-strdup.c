#include "main.h"

/**
 * _strdup - Returns a pointer to a newly-allocated space in memory
 *           containing a copy of the string given as parameter.
 * @str: The string to be copied.
 *
 * Return: If str == NULL or insufficient memory is available - NULL.
 *         Otherwise - a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	char *ptr;
	int len = 0;
	int i;

	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;

	ptr = malloc(sizeof(*str) * len + 1);
	if (ptr == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}

	ptr[i] = '\0';

	return (ptr);
}
