#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_strings - Prints strings, followed by a new line.
 * @separator: The string to be printed between strings.
 * @n: The number of strings passed to the function.
 * @...: A variable number of strings to be printed.
 *
 * Description: If separator is NULL, it is not printed.
 *              If one of the strings if NULL, (nil) is printed instead.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *s;

	if (!n && separator == NULL)
	{
		printf("\n");
		return;
	}

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		s = va_arg(args, char *);
		if (!s)
		{
			printf("(nil)");
		}
		printf("%s", s);
		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
