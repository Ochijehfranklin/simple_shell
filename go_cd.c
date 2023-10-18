#include "shell.h"
/**
 * go_cd - This function will change current directory of shell
 * @args: array of arguments
 * @fist: pointer to beginning of args
 * Return: returns when successful, -2
 * if not a directory nd -1 if error
 */
int go_cd(char **args, char __attribute__((__unused__)) **fist)
{
	struct stat dr;
	char **pathInf, *freshline = "\n", *prevdr = NULL, *pw = NULL;

	prevdr = getcwd(prevdr, 0);
	if (!prevdr)
		return (-1);
	if (args[0])
	{
		if (*(args[0]) == '-' || our_strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (get_env("OLDPWD") != NULL)
					(chdir(*get_env("OLDPWD") + 7));
			}
			else
			{
				free(prevdr);
				return (our_error(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &dr) == 0 && S_ISDIR(dr.st_mode)
					&& ((dr.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(prevdr);
				return (our_error(args, 2));
			}
		}
	}
	else
	{
		if (get_env("HOME") != NULL)
			chdir(*(get_env("HOME")) + 5);
	}
	pw = getcwd(pw, 0);
	if (!pw)
		return (-1);
	pathInf = malloc(sizeof(char *) * 2);
	if (!pathInf)
		return (-1);
	pathInf[0] = "OLDPWD";
	pathInf[1] = prevdr;
	if (set_goenv(pathInf, pathInf) == -1)
		return (-1);
	pathInf[0] = "PWD";
	pathInf[1] = pw;
	if (set_goenv(pathInf, pathInf) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, pw, our_strlength(pw));
		write(STDOUT_FILENO, freshline, 1);
	}
	free(prevdr);
	free(pw);
	free(pathInf);
	return (0);
}
