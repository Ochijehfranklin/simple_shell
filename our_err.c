#include "shell.h"
/**
 * our_error - customized error to standard error
 * @args: array of arguments
 * @error: error value
 * Return: error
 */
int our_error(char **args, int error)
{
	char *err;

	switch (error)
	{
		case -1:
			err = env_err(args);
			break;
		case 2:
			if (*(args[0]) == 'e')
				err = exit_err(++args);
			else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
				err = syntax_err(args);
			else
				err = cd_err(args);
			break;
		case 126:
			err = error_126(args);
			break;
		case 127:
			err = error_127(args);
			break;
	}
	write(STDERR_FILENO, err, our_strlength(err));
	if (err)
		free(err);
	return (error);
}
