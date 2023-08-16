#include "3-calc.h"

/**
 * main - Prints the result of simple operations.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char **argv)
{
	int (*func)(int, int), n1, n2;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	n1 = atoi(argv[1]);
	func = get_op_func(argv[2]);
	n2 = atoi(argv[3]);

	if (!func)
	{
		printf("Error\n");
		exit(99);
	}
	if ((n2 == 0 && (argv[2][0]) == '/') || (n2 == 0 && (argv[2][0]) == '%'))
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", func(n1, n2));
	return (0);
}
