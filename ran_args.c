#include "shell.h"

/**
 * ran_args - runs the executn of commands
 * @args: argument array
 * @arg0: start of array
 * @retrn: last executed command of parent
 * Return: value of last executed cmd of parent
 */
int ran_args(char **args, char **arg0, int *retrn)
{
	int retrn_val, x;
	int (*builtin)(char **args, char **arg0);

	builtin = checkbuiltins(args[0]);

	if (builtin)
	{
		retrn_val = builtin(args + 1, arg0);
		if (retrn_val != EXIT)
			*retrn = retrn_val;
	}
	else
	{
		*retrn = child_exec(args, arg0);
		retrn_val = *retrn;
	}
	cmdhist++;
	x = 0;
	while (args[x])
	{
		free(args[x]);
		x++;
	}

	return (retrn_val);
}

