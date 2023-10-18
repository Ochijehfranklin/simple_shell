#include "shell.h"

/**
 * change_var - to change variable when needed
 * @args: pointer fo args in command line
 * @retrn: returns a pointer to latest value in command
 * Return: returns void.
 */
void change_var(char **args, int *retrn)
{
	int length, x, y;
	char *new_lyn, *old_lyn, *val;

	old_lyn = *args;
	x = 0;
	val = NULL;
	y = 0;
	while (old_lyn[x])
	{
		if (old_lyn[x] == '$' && old_lyn[x + 1] && old_lyn[x + 1] != ' ')
		{
			if (old_lyn[x + 1] == '$')
			{
				val = pick_pid();
				y = x + 2;
			}
			else if (old_lyn[x + 1] == '?')
			{
				val = hatoi(*retrn);
				y = x + 2;
			}
			else if (old_lyn[x + 1])
			{
				y = x + 1;
				while (old_lyn[y] && old_lyn[y] != '$' && old_lyn[y] != ' ')
					y++;
				length = y - (x + 1);
				val = our_envalue(&old_lyn[x + 1], length);
			}
			new_lyn = malloc(x + our_strlength(val) + our_strlength(&old_lyn[y]) + 1);
			if (!args)
				return;
			new_lyn[0] = '\0';
			our_strncat(new_lyn, old_lyn, x);
			if (val)
			{
				our_strcat(new_lyn, val);
				free(val);
				val = NULL;
			}
			our_strcat(new_lyn, &old_lyn[y]);
			free(old_lyn);
			*args = new_lyn;
			old_lyn = new_lyn;
			x = -1;
		}
		x++;
	}
}
