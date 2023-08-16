#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the codes of itself.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int b, i;
	int (*address)(int, char **) = main;
	unsigned char code;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	b = atoi(argv[1]);

	if (b < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < b; i++)
	{
		code = *(unsigned char *)address;
		printf("%.2x", code);

		if (i == b - 1)
			continue;
		printf(" ");

		address++;
	}

	printf("\n");

	return (0);
}
