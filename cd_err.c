#include "shell.h"

/**
 * cd_err - cd error for cd
 * @args: array of args
 * Return: error gotten
 */
char *cd_err(char **args)
{
	int length;
	char *err, *history;

	history = hatoi(cmdhist);
	if (!history)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
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
	if (args[0][0] == '-')
		our_strcat(err, ": cd: un_availed option ");
	else
		our_strcat(err, ": cd: cannot cd this ");
	our_strcat(err, args[0]);
	our_strcat(err, "\n");

	free(history);
	return (err);
}

