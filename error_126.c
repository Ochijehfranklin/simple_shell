#include "shell.h"


/**
 * error_126 - Creates an error message for permission denied failures
 * @args: An array of arguments passed to the command line
 * Return: The error string
 */
char *error_126(char **args)
{
	int length;
	char *err, *history;

	history = hatoi(cmdhist);
	if (!history)
		return (NULL);

	length = our_strlength(nam) +
		our_strlength(history) + our_strlength(args[0]) + 24;
	err = malloc(sizeof(*err) * (length + 1));
	if (!err)
	{
		free(history);
		return (NULL);
	}
	our_strcpy(err, nam);
	our_strcat(err, ": ");
	our_strcat(err, history);
	our_strcat(err, ": ");
	our_strcat(err, args[0]);
	our_strcat(err, ": Permission denied\n");

	free(history);
	return (err);
}

