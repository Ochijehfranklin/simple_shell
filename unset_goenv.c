#include "shell.h"
/**
 * unset_goenv - removes env var from path
 * @args: arrsay of args
 * @arg0: pointer to start of args
 * Return: 0 (success), -1 (fail)
 */
int unset_goenv(char **args, char __attribute__((__unused__)) **arg0)
{
	int x, y;
	char **envi, **nue_env;
	size_t scale;

	if (!args[0])
		return (our_error(args, -1));
	envi = get_env(args[0]);
	if (!envi)
		return (0);
	scale = 0;
	while (environ[scale])
		scale++;
	nue_env = malloc(sizeof(char *) * scale);
	if (!nue_env)
		return (our_error(args, -1));
	x = 0;
	y = 0;
	while (environ[x])
	{
		if (*envi == environ[x])
		{
			free(*envi);
			continue;
		}
		nue_env[y] = environ[x];
		y++;
		x++;
	}
	free(environ);
	environ = nue_env;
	environ[scale - 1] = NULL;
	return (0);
}
