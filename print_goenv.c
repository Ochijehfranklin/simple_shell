#include "shell.h"

/**
 * print_goenv - function that prints the current environment
 * @args: array of arguments passed to shell
 * @arg0: pointer to the start of argument
 *
 * Return: 0 on success, -1 on failure
 */
int print_goenv(char **args, char __attribute__((__unused__)) **arg0)
{
	int x;
	char freshline = '\n';

	(void)args;
	if (!environ)
		return (-1);
	x = 0;
	while (environ[x])
	{
		write(STDOUT_FILENO, environ[x], our_strlength(environ[x]));
		write(STDOUT_FILENO, &freshline, 1);
		x++;
	}
	return (0);
}
