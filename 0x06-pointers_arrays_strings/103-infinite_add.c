#include "main.h"

/**
 * infinite_add - Adds two numbers.
 * @n1: The first number to be added.
 * @n2: The second number to be added.
 * @r: The buffer to store the result.
 * @size_r: The buffer size.
 *
 * Return: If r can store the sum - a pointer to the result.
 *         If r cannot store the sum - 0.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k, len = 0, dig1, dig2, left = 0;

	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;
	if (i > j)
		len = i;
	else
		len = j;
	if (len + 1 > size_r)
		return (0);
	r[len] = '\0';
	for (k = len - 1; k >= 0; k--)
	{
		i--;
		j--;
		if (i >= 0)
			dig1 = n1[i] - '0';
		else
			dig1 = 0;
		if (j >= 0)
			dig2 = n2[j] - '0';
		else
			dig2 = 0;
		r[k] = (dig1 + dig2 + left) % 10 + '0';
		left = (dig1 + dig2 + left) / 10;
	}
	if (left == 1)
	{
		r[len + 1] = '\0';
		if (len + 2 > size_r)
			return (0);
		while (len-- >= 0)
			r[len + 1] = r[len];
		r[0] = left + '0';
	}
	return (r);
}
