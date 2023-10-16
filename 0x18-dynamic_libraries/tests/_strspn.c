#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be searched.
 * @accept: The string containing characters to match in s.
 *
 * Return: The number of bytes in the initial segment of s
 * which consist only of characters from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int len = 0;
	int found = 1;

	while (*s && found)
	{
		int i = 0;

		found = 0;
		while (accept[i])
		{
			if (*s == accept[i])
			{
				len++;
				found = 1;
				break;
			}
			i++;
		}
		if (found)
			s++;
	}
	return (len);
}
