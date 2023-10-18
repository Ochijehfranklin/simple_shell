#include "shell.h"

/**
 * error_127 - This function creates error msg when command is not found
 * @args: this is the array of args passed
 * Return: d error string
 */
char *error_127(char **args)
{
	int length;
	char *err, *history;


	history = hatoi(cmdhist);
	if (!history)
		return (NULL);

	length = our_strlength(nam) +
		our_strlength(history) + our_strlength(args[0]) + 16;
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
	our_strcat(err, ": not found\n");


	free(history);
	return (err);
}
