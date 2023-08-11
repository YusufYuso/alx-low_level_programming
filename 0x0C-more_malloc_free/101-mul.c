#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void _puts(const char *str);
int _isdigit(int c);
int _strlen(char *s);
char *big_mul(char *s1, char *s2);

/**
 * _puts - Prints a string to stdout.
 * @str: The string to be printed.
 */
void _puts(const char *str)
{
	while (*str)
		_putchar(*str++);

	_putchar('\n');
}

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * big_mul - multiply two big number strings
 * @s1: the first big number string
 * @s2: the second big number string
 *
 * Return: the product big number string
 */
char *big_mul(char *s1, char *s2)
{
	char *result;
	int len, l1, l2, a, b, carry;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	len = l1 + l2 + 1;
	a = l1 + l2;
	result = malloc(sizeof(int) * len);
	if (!result)
		_puts("Error"), exit(98);
	while (a--)
		result[a] = 0;

	for (l1 -= 1; l1 >= 0; l1--)
	{
		if (!_isdigit(s1[l1]))
		{
			free(result);
			_puts("Error"), exit(98);
		}
		a = s1[l1] - '0';
		carry = 0;

		for (l2 = _strlen(s2) - 1; l2 >= 0; l2--)
		{
			if (!_isdigit(s2[l2]))
			{
				free(result);
				_puts("Error"), exit(98);
			}
			b = s2[l2] - '0';

			carry += result[l1 + l2 + 1] + (a * b);
			result[l1 + l2 + 1] = carry % 10;

			carry /= 10;
		}
		if (carry)
			result[l1 + l2 + 1] += carry;
	}
	return (result);
}

/**
 * main - multiply two big number strings
 * @argc: the number of arguments
 * @argv: the argument vector
 *
 * Return: Always 0 on success.
 */
int main(int argc, char **argv)
{
	char *result;
	int flag = 0, index = 0, len;

	if (argc != 3)
		_puts("Error"), exit(98);

	len = _strlen(argv[1]) + _strlen(argv[2]);
	result = big_mul(argv[1], argv[2]);
	while (index < len)
	{
		if (result[index])
			flag = 1;
		if (flag)
			_putchar(result[index] + '0');
		index++;
	}
	if (!flag)
		_putchar('0');
	_putchar('\n');
	free(result);
	return (0);
}
