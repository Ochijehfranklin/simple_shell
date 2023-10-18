#include "shell.h"
/**
 * our_envalue - This function fetches the value associated with an environment variable
 * @var: variable we search for in the environment
 * @length: The length of environment variable being searched for
 * Return: envFetched
 */

char *our_envalue(char *var, int length)
{
	char *x, *envName, **envAddr, *envFetched = NULL;

	envName = malloc(length + 1);
	if (!envName)
		return (NULL);
	envName[0] = '\0';
	our_strncat(envName, var, length);
	envAddr = get_env(envName);
	free(envName);
	if (envAddr)
	{
		x = *envAddr;
		while (*x != '=')
			x++;
		x++;
		envFetched = malloc(our_strlength(x) + 1);
		if (envFetched)
			our_strcpy(envFetched, x);
	}
	return (envFetched);
}
