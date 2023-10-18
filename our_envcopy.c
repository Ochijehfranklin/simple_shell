#include "shell.h"

/**
 * our_envcopy - Function to create copy environ
 * Return: a pointer to the new copy
 */
char **our_envcopy(void)
{
	int x, y;
	size_t sizes;
	char **fresh_env;

	sizes = 0;
	while (environ[sizes])
		sizes++;

	fresh_env = malloc(sizeof(char *) * (sizes + 1));
	if (!fresh_env)
		return (NULL);

	x = 0;
	while (environ[x])
	{
		fresh_env[x] = malloc(our_strlength(environ[x]) + 1);

		if (!fresh_env[x])
		{
			for (y = 0; y < x; y++)
			{
				free(fresh_env[y]);
			}
			free(fresh_env);
			return (NULL);
		}
		our_strcpy(fresh_env[x], environ[x]);
		x++;
	}
	fresh_env[x] = NULL;

	return (fresh_env);
}
