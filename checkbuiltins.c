#include "shell.h"

/**
 * checkbuiltins - search for command in builtin list
 * @cmds: Command we intend to match
 * Return: pointer to builtin
 */
int (*checkbuiltins(char *cmds))(char **args, char **arg0)
{
	int x;

	builtinz cmdlist[] = {
		{"exit", exit_goshell},
		{"env", print_goenv},
		{"setenv", set_goenv},
		{"unsetenv", unset_goenv},
		{"cd", go_cd },
		{NULL, NULL}
	};
	x = 0;
	while (cmdlist[x].nam)
	{
		if (our_strcmp(cmdlist[x].nam, cmds) == 0)
			break;
		x++;
	}
	return (cmdlist[x].fpt);
}
