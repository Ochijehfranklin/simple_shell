#include "shell.h"

/**
 * set_goenv - This function changes an environment variable
 * @args: array of arguments
 * @arg0: pointer to the start of argument
 * Return: 0 on succes, 1on failure
 */
int set_goenv(char **args, char __attribute__((__unused__)) **arg0)
{
	int x;
	size_t scale;
	char *nue_env, **env_arr, **envi = NULL;

	if (!args[0] || !args[1])
		return (our_error(args, -1));

	nue_env = malloc(our_strlength(args[0]) + 1 + our_strlength(args[1]) + 1);
	if (!nue_env)
		return (our_error(args, -1));
	our_strcpy(nue_env, args[0]);
	our_strcat(nue_env, "=");
	our_strcat(nue_env, args[1]);
	envi = get_env(args[0]);
	if (envi)
	{
		free(*envi);
		*envi = nue_env;
		return (0);
	}
	scale = 0;
	while (environ[scale])
		scale++;
	env_arr = malloc(sizeof(char *) * (scale + 2));
	if (!env_arr)
	{
		free(nue_env);
		return (our_error(args, -1));
	}

	x = 0;
	while (environ[x])
	{
		env_arr[x] = environ[x];
		x++;
	}

	free(environ);
	environ = env_arr;
	environ[x] = nue_env;
	environ[x + 1] = NULL;

	return (0);
}

