#include "main.h"

/**
 * array_range - Creates an array of integers ordered
 *               from min to max, inclusive.
 * @min: The first value of the array.
 * @max: The last value of the array.
 *
 * Return: If min > max or the function fails - NULL.
 *         Otherwise - a pointer to the newly created array.
 */
int *array_range(int min, int max)
{
	int len = 0, i;
	int *ptr;

	if (min > max)
		return (NULL);

	for (i = min; i <= max; i++)
		len++;

	ptr = malloc(sizeof(*ptr) * len);

	if (ptr == NULL)
		return (NULL);

	len = 0;
	for (i = min; i <= max; i++)
		ptr[len++] = i;
	return (ptr);
}
