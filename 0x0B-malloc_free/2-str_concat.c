#include "main.h"

/**
 * str_concat - Concatenates two strings.
 * @s1: The string to be concatenated upon.
 * @s2: The string to be concatenated to s1.
 *
 * Return: If concatenation fails - NULL.
 *         Otherwise - a pointer the newly-allocated space in memory
 *                     containing the concatenated strings.
 */
char *str_concat(char *s1, char *s2)
{
	int len1 = 0;
	int len2 = 0;
	int len;
	int i = 0;
	char *ptr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;

	while (s2[len2])
		len2++;

	len = len1 + len2;

	ptr = malloc(sizeof(char) * len + 1);

	if (ptr == NULL)
		return (NULL);

	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		ptr[len1] = s2[i];
		i++;
		len1++;
	}

	ptr[len + 1] = '\0';
	return (ptr);
}
