#include "shell.h"

/**
 * child_exec - Executes a command in a child process
 * @args: An array of arguments
 * @fist: A double pointer to the start of args
 * Return: On SUCCESS, returns the exit value of the last executed command
 *	   If an error occurs returns the associated error code
 */
int child_exec(char **args, char **fist)
{
	pid_t child_pid;
	int stats, flags, retrn;
	char *cmds;

	flags = 0;
	retrn = 0;
	cmds = args[0];
	if (cmds[0] != '/' && cmds[0] != '.')
	{
		flags = 1;
		cmds = path_locate(cmds);
	}
	if (!cmds || (access(cmds, F_OK) == -1))
	{
		if (errno == EACCES)
			retrn = (our_error(args, 126));
		else
			retrn = (our_error(args, 127));
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			if (flags)
				free(cmds);
			perror("Error child:");
			return (1);
		}
		if (child_pid == 0)
		{
			execve(cmds, args, environ);
			if (errno == EACCES)
			{
				retrn = (our_error(args, 126));
			}
			fri_env();
			fri_args(args, fist);
			_exit(retrn);
		}
		else
		{
			wait(&stats);
			retrn = WEXITSTATUS(stats);
		}
	}
	if (flags)
	{
		free(cmds);
	}
	return (retrn);
}
