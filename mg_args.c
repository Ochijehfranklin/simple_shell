#include "shell.h"

/**
 * mg_args - handles arguments like calls, gets and runs execution of commands
 * @retrn: value of last executed process of parents
 * Return: -1 if input can't be
 * tokenized, _EOF for end-of-file or exit value of last command
 */
int mg_args(int *retrn)
{
	char **args, **arg0, *lyne;
	int x, retur_val;

	retur_val = 0;
	lyne = NULL;
	lyne = _getArgs(lyne, retrn);
	if (!lyne)
		return (my_EOF);
	args = our_strtok(lyne, " ");
	free(lyne);
	if (!args)
		return (retur_val);
	if (look_args(args) != 0)
	{
		*retrn = 2;
		fri_args(args, args);
		return (*retrn);
	}
	arg0 = args;
	x = 0;
	while (args[x])
	{
		if (our_strncmp(args[x], ";", 1) == 0)
		{
			free(args[x]);
			args[x] = NULL;
			retur_val = kal_args(args, arg0, retrn);
			args = &args[++x];
			x = 0;
		}
		x++;
	}
	if (args)
		retur_val = kal_args(args, arg0, retrn);
	free(arg0);

	return (retur_val);
}
