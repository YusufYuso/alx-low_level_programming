#include "main.h"
char **strtow(char *str);
int countw(char *s);

/**
 * countw - Counts the number of words contained within a string.
 * @s: The string to be searched.
 *
 * Return: The number of words contained within str.
 */
int countw(char *s)
{
	int i, count = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == ' ')
		{
			if (s[i + 1] != ' ' && s[i + 1] != '\0')
				count++;
		}
		else if (i == 0)
			count++;
	}
	count++;
	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 *
 * Return: If str = NULL, str = "", or the function fails - NULL.
 *         Otherwise - a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	int i, j, k, l, n = 0, wc = 0;
	char **ptr;

	if (str == NULL || *str == '\0')
		return (NULL);

	n = countw(str);
	if (n == 1)
		return (NULL);

	ptr = (char **)malloc(sizeof(char *) * n);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
				;
			j++;
			ptr[wc] = (char *)malloc(sizeof(char) * j);
			j--;
			if (ptr[wc] == NULL)
			{
				for (k = 0; k < wc; k++)
					free(ptr[k]);
				free(ptr[n - 1]);
				free(ptr);
				return (NULL);
			}
			for (l = 0; l < j; l++)
				ptr[wc][l] = str[i + l];
			ptr[wc][l] = '\0';
			wc++;
			i += j;
		}
		else
			i++;
	}
	return (ptr);
}
