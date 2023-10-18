#include "shell.h"

/**
 * look_args - This function checks for ';;', '&&', ';' or '||'
 * @args: tokenized args and commands
 * Return: 0 on success, and -2 if the signs ('||', ';', or '&&') are invalid
 */
int look_args(char **args)
{
	char *curchar, *next;
	size_t x;

	x = 0;
	while (args[x])
	{
		curchar = args[x];
		if (curchar[0] == ';' || curchar[0] == '&'
				|| curchar[0] == '|')
		{
			if (x == 0 || curchar[1] == ';')
				return (our_error(&args[x], 2));
			next = args[x + 1];
			if (next && (next[0] == ';' || next[0] == '&' || next[0] == '|'))
				return (our_error(&args[x + 1], 2));
		}
		x++;
	}
	return (0);
}

