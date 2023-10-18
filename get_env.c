#include "shell.h"

/**
 * get_env - This function would get the environment variable from PATH
 * @vra: name of the environment variable to be gotten
 * Return: value to environment variable or NULL
 */
char **get_env(const char *vra)
{
	int x, length;

	length = our_strlength(vra);
	x = 0;
	while (environ[x])
	{
		if (our_strncmp(vra, environ[x], length) == 0)
			return (&environ[x]);
		x++;
	}
	return (NULL);
}
