#include "shell.h"

/**
 * fri_args - This function frees memory taken up by arguments
 * @args: points to command entered
 * @arg0: points to starting argumnent
 */

void fri_args(char **args, char **arg0)
{
	size_t x;

	x = 0;
	while (args[x] || args[x + 1])
	{
		free(args[x]);
		x++;
	}
	free(arg0);
}
