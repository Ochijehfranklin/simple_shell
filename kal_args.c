#include "shell.h"
/**
 * kal_args - This function separates ops from cmds and thn call the command
 * @args: array of args
 * @arg0: starting argument
 * @retrn: last executed cmd of parent
 * Return: value of last executed command
 */
int kal_args(char **args, char **arg0, int *retrn)
{
	int retur_val, x;

	if (!args[0])
		return (*retrn);
	x = 0;
	while (args[x])
	{
		if (our_strncmp(args[x], "||", 2) == 0)
		{
			free(args[x]);
			args[x] = NULL;
			retur_val = ran_args(args, arg0, retrn);
			if (*retrn != 0)
			{
				args = &args[++x];
				x = 0;
			}
			else
			{
				for (x++; args[x]; x++)
					free(args[x]);
				return (retur_val);
			}
		}
		else if (our_strncmp(args[x], "&&", 2) == 0)
		{
			free(args[x]);
			args[x] = NULL;
			retur_val = ran_args(args, arg0, retrn);
			if (*retrn == 0)
			{
				args = &args[++x];
				x = 0;
			}
			else
			{
				for (x++; args[x]; x++)
					free(args[x]);
				return (retur_val);
			}
		}
		x++;
	}
	retur_val = ran_args(args, arg0, retrn);
	return (retur_val);
}
