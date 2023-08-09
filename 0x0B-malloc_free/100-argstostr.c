#include "main.h"

int get_len(char *av);
char *argstostr(int ac, char **av);

/**
 * get_len - finds length of a string
 * @av: string
 *
 * Return: length of the string av
 */
int get_len(char *av)
{
	int len = 0;

	while (av[len])
		len++;
	return (len);
}

/**
 * argstostr - Concatenates all arguments of the program into a string;
 *             arguments are separated by a new line in the string.
 * @ac: The number of arguments passed to the program.
 * @av: An array of pointers to the arguments.
 *
 * Return: If ac == 0, av == NULL, or the function fails - NULL.
 *         Otherwise - a pointer to the new string.
 */
char *argstostr(int ac, char **av)
{
	int i = 0;
	int j = 0;
	int cpt = 0;
	int nc = 0;
	char *ptr;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (; i < ac; i++)
		nc += get_len(av[i]);

	ptr = malloc(sizeof(char) * nc);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, cpt++)
			ptr[cpt] = av[i][j];
		ptr[cpt] = '\n';
		cpt++;
	}
	ptr[cpt] = '\0';
	return (ptr);
}
