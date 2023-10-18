#include "shell.h"

/**
 * exit_err - this function takes care of shell exit errors
 * @args: Array of arguments
 * Return: error
 */
char *exit_err(char **args)
{
	int length;
	char *err, *history;

	history = hatoi(cmdhist);
	if (!history)
		return (NULL);

	length = our_strlength(nam) +
		our_strlength(history) + our_strlength(args[0]) + 27;
	err = malloc(sizeof(*err) * (length + 1));
	if (!err)
	{
		free(history);
		return (NULL);
	}
	our_strcpy(err, nam);
	our_strcat(err, ": ");
	our_strcat(err, history);
	our_strcat(err, ": exit: not good number: ");
	our_strcat(err, args[0]);
	our_strcat(err, "\n");

	free(history);
	return (err);
}
