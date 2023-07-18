#include "main.h"

/**
* print_to_98 - prints all natural numbers from n to 98
* followed by a new line.
* @n: from n to 98
*/
void print_to_98(int n)
{
	if (n >= 98)
	{
		int i;

		for (i = n; i >= 98; i--)
		{
			_putchar(i);
			_putchar(',');
			_putchar(' ');
		}
	}
	else
	{
		int i;

		for (i = n; i < 98; i++)
		{
			_putchar(i);
			_putchar(',');
			_putchar(' ');
		}
	}
}
