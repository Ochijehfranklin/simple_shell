#include "shell.h"


/**
 * exit_goshell - This would exit our go shell
 * @get_args: commands to execute
 * @fist: the first argument
 * Return: -3 (no arg) and (-2) invalid exit
 */
int exit_goshell(char **get_args, char **fist)
{
	int x, maxLength = 10;
	unsigned int y = 0, maxi = 1 << (sizeof(int) * 8 - 1);

	if (get_args[0])
	{
		if (get_args[0][0] == '+')
		{
			x = 1;
			maxLength++;
		}
		x = 0;
		while (get_args[0][x])
		{
			if (x <= maxLength && get_args[0][x] >= '0' && get_args[0][x] <= '9')
				y = (y * 10) + (get_args[0][x] - '0');
			else
				return (our_error(--get_args, 2));
			x++;
		}
	}
	else
	{
		return (-3);
	}
	if (y > maxi - 1)
		return (our_error(--get_args, 2));
	get_args -= 1;
	fri_args(get_args, fist);
	fri_env();
	exit(y);
}
