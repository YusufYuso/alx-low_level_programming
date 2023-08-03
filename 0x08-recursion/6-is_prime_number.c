#include "main.h"

int is_prime_number(int n);
int primeno(int n, int i);

/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to be checked.
 *
 * Return: If the integer is not prime - 0.
 *         If the number is prime - 1.
 */
int is_prime_number(int n)
{
	return (primeno(n, 2));
}

/**
 * primeno - Checks if a number is divisible.
 * @n: The number to be checked.
 * @i: The divisor.
 *
 * Return: If the number is divisible - 0.
 *         If the number is not divisible - 1.
 */
int primeno(int n, int i)
{
	if (i >= n && n > 1)
	{
		return (1);
	}
	else
	{
		if (n % i == 0 || n <= 1)
		{
			return (0);
		}
		else
		{
			return (primeno(n, i + 1));
		}
	}
}
