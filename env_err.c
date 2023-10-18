#include "shell.h"

/**
 * env_err - custom error message that prints
 * @args: Argument array
 * Return: error value
 */
char *env_err(char **args)
{
	int length;
	char *err, *hist_st;

	hist_st = hatoi(cmdhist);
	if (!hist_st)
		return (NULL);
	args--;
	length = our_strlength(nam) +
		our_strlength(hist_st) + our_strlength(args[0]) + 45;
	err = malloc(sizeof(*err) * (length + 1));
	if (!err)
	{
		free(hist_st);
		return (NULL);
	}
	our_strcpy(err, nam);
	our_strcat(err, ": ");
	our_strcat(err, hist_st);
	our_strcat(err, ": ");
	our_strcat(err, args[0]);
	our_strcat(err, ": cannot do add/remove from environment\n");

	free(hist_st);
	return (err);
}
