#include "main.h"

int _sqrt(int num, int value);
int _sqrt_recursion(int n);
/**
 * _sqrt - Finds the natural square root of an inputted number.
 * @num: The number to find the square root of.
 * @value: The root to be tested.
 *
 * Return: If the number has a natural square root - the square root.
 *         If the number does not have a natural square root - -1.
 */
int _sqrt(int num, int value)
{
	if ((value * value) == num)
		return (value);

	else if ((value * value) < num)
		return (_sqrt(num, value + 1));
	else
		return (-1);
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to return the square root of.
 *
 * Return: If n has a natural square root - the natural square root of n.
 *         If n does not have a natural square root - -1.
 */
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}
