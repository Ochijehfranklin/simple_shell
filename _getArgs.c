#include "shell.h"

/**
 * _getArgs - This function gets command from stdin
 * @lin: stores our command
 * @retrn: value of last executed cmd
 * Return: lin on success
 */
char *_getArgs(char *lin, int *retrn)
{
	char *request = "Goshell ";
	size_t typed = 0;
	ssize_t x;

	if (lin)
		free(lin);
	x = our_getline(&lin, &typed, STDIN_FILENO);
	if (x == -1)
		return (NULL);
	if (x == 1)
	{
		cmdhist++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, request, 8);
		return (_getArgs(lin, retrn));
	}
	lin[x - 1] = '\0';
	change_var(&lin, retrn);
	break_line(&lin, x);
	return (lin);
}
