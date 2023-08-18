#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - Prints anything, followed by a new line.
 * @format: A string of characters representing the argument types.
 * @...: A variable number of arguments to be printed.
 *
 * Description: Any argument not of type char, int, float,
 *              or char * is ignored.
 *              If a string argument is NULL, (nil) is printed instead.
 *
 * Return: it returns nothing
 */
void print_all(const char *const format, ...)
{
	va_list args;
	char *s, *separator = "";
	unsigned int i = 0;

	va_start(args, format);

	if (format)
	{
		while (format[i] != '\0')
		{
			switch (format[i])
			{
			case 'c':
				printf("%s%c", separator, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", separator, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", separator, va_arg(args, double));
				break;
			case 's':
				s = va_arg(args, char *);
				printf("%s%s", separator, !s ? "(nil)" : s);
				break;
			default:
				break;
			}
			separator = ", ";
			i++;
		}
	}
	printf("\n");
	va_end(args);
}
