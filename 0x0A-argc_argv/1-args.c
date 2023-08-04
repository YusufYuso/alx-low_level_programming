#include <stdio.h>

/**
 * main - prints the number of arguments passed into it.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char __attribute__((__unused__)) *argv[])
{
	int count = argc - 1;

	printf("%d\n", count);
	return (0);
}
