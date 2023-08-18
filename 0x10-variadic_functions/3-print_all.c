#include "variadic_functions.h"
#include <stdio.h>

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
				printf("%s%s", separator, s ? s : "(nil)");
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
