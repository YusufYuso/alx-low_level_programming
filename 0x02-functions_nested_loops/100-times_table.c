#include "main.h"

/**
* print_times_table - prints the n times table, starting with 0.
* @n: times table for n
*
* Return: times table starting with 0
*/
void print_times_table(int n)
{
	int num, m, p;

	if (n > 15 && n < 0)
		exit(0);
	for (num = 0; num <= n; num++)
	{
		_putchar('0);
		for (m = 1; m <= n; m++)
		{
			_putchar(',');
			_putchar(' ');
			p =  num * m;
			if (p <= 9)
				_putchar(' ');
			else
				_putchar((p / 10) + '0');
			_putchar((p % 10) + '0');
		}
		_putchar('\n');
	}
}
