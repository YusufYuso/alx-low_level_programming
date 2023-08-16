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
	int n1, n2, value;
	char *op;
	int (*fun)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	n1 = atoi(argv[1]);
	op = argv[2];
	n2 = atoi(argv[3]);
	fun = get_op_func(op);

	if (op[1] != '\0' || fun == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	if ((n2 == 0 && *op == '/') || (n2 == 0 && *op == '%'))
	{
		printf("Error\n");
		exit(100);
	}
	value = f(n1, n2);
	printf("%d\n", value);

	return (0);
}
