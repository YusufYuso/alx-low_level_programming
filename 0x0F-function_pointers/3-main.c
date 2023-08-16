#include "3-calc.h"

/**
 * main - Prints the result of simple operations.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int n1, n2, result;
	char *op;
	int (*fun)(int, int);

	fun = get_op_func(argv[2]);

	if (!fun)
	{
		printf("Error\n");
		exit(99);
	}

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	n1 = atoi(argv[1]);
	op = argv[2];
	n2 = atoi(argv[3]);

	if (op[1] != '\0' || get_op_func(op) == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	if ((n2 == 0 && *op == '/') || (n2 == 0 && *op == '%'))
	{
		printf("Error\n");
		exit(100);
	}
	result = fun(atoi(argv[1]), atoi(argv[3]));
	printf("%d\n", result);
	return (0);
}
