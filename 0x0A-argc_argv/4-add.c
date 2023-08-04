#include <stdio.h>

int get_num(char *argv);

/**
 * get_num - function to convert string to int.
 * @argv: a pointer to string of character
 *
 * Return: int number.
 */
int get_num(char *argv)
{
	int i;
	unsigned int num = 0;
	int sign = 1;

	for (i = 0; argv[i] != '\0'; i++)
	{
		if (argv[i] == '-')
			continue;
		num = (num * 10) + (argv[i] - '0');
	}
	if (argv[0] == '-')
		sign *= -1;
	return (num * sign);
}
/**
 * main - a program that multiplies two numbers.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int result = 0;
	char *i;


	while (--argc)
	{
		for (i = argv[argc]; *i; i++)
		{
			if (*i == '-')
				continue;
			if (*i < '0' || *i > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		result += get_num(argv[argc]);
	}
	printf("%d\n", result);
	return (0);
}
