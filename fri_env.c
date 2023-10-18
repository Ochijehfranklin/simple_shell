#include "shell.h"

/**
 * fri_env - to frr the env copy
 */
void fri_env(void)
{
	int x;

	x = 0;
	while (environ[x])
	{
		free(environ[x]);
		x++;
	}
	free(environ);
}
