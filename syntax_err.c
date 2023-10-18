#include "shell.h"

/**
 * syntax_err - customized error for syntax
 * @args: array of args
 * Return: error
 */
char *syntax_err(char **args)
{
	int length;
	char *err, *history;

	history = hatoi(cmdhist);
	if (!history)
		return (NULL);

	length = our_strlength(nam) +
		our_strlength(history) + our_strlength(args[0]) + 33;
	err = malloc(sizeof(*err) * (length + 1));
	if (!err)
	{
		free(history);
		return (NULL);
	}
	our_strcpy(err, nam);
	our_strcat(err, ": ");
	our_strcat(err, history);
	our_strcat(err, ": Syntax err: \"");
	our_strcat(err, args[0]);
	our_strcat(err, "\" un-expected\n");

	free(history);
	return (err);
}
