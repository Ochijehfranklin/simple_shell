#include "shell.h"


/**
 * fopen_error - This function prints error if file cant be accessed
 * @path: Path to the file
 * Return: Returns (127)
 */
int fopen_error(char *path)
{
	int length;
	char *err, *histString;


	histString = hatoi(cmdhist);
	if (!histString)
		return (127);


	length = our_strlength(nam) +
		our_strlength(histString) + our_strlength(path) + 16;
	err = malloc(sizeof(char) * (length + 1));
	if (!err)
	{
		free(histString);
		return (127);
	}
	our_strcpy(err, nam);
	our_strcat(err, ": ");
	our_strcat(err, histString);
	our_strcat(err, ": Can't open ");
	our_strcat(err, path);
	our_strcat(err, "\n");
	free(histString);
	write(STDERR_FILENO, err, length);
	free(err);
	return (127);
}

