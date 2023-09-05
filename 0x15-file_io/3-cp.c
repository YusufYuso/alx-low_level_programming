#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define E_NOREAD "Error: Can't read from file %s\n"
#define E_NOWRITE "Error: Can't write to %s\n"
#define E_NOCLOSE "Error: Can't close fd %d\n"
#define PERMISSIONS (0664)
#define BUF_SIZE 1024

/**
 * main - program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 1 on success 0 on failure
 */
int main(int ac, char **av)
{
	int from = 0, to = 0;
	ssize_t b;
	char buf[BUF_SIZE];

	if (ac != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);

	from = open(av[1], O_RDONLY);
	if (from == -1)
		dprintf(STDERR_FILENO, E_NOREAD, av[1]), exit(98);

	to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (to == -1)
		dprintf(STDERR_FILENO, E_NOWRITE, av[2]), exit(99);

	while ((b = read(from, buf, BUF_SIZE)) > 0)
		if (write(to, buf, b) != b)
			dprintf(STDERR_FILENO, E_NOWRITE, av[2]), exit(99);

	if (b == -1)
		dprintf(STDERR_FILENO, E_NOREAD, av[1]), exit(98);

	from = close(from);
	to = close(to);

	if (from)
		dprintf(STDERR_FILENO, E_NOCLOSE, from), exit(100);

	if (to)
		dprintf(STDERR_FILENO, E_NOCLOSE, from), exit(100);

	return (EXIT_SUCCESS);
}
