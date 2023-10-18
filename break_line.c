#include "shell.h"

/**
 * break_line - This breaks a line from stdin
 * @lyn: pointer to broken line from stdin
 * @length: The length of the line
 */
void break_line(char **lyn, ssize_t length)
{
	size_t x, y;
	ssize_t new_length;
	char *old_lyn, *new_lyn, previous, latestchar, next;

	new_length = newLength(*lyn);

	if (new_length == length - 1)
		return;
	new_lyn = malloc(new_length + 1);
	if (!new_lyn)
		return;
	y = 0;
	old_lyn = *lyn;
	x = 0;
	while (old_lyn[x])
	{
		latestchar = old_lyn[x];
		next = old_lyn[x + 1];
		if (x != 0)
		{
			previous = old_lyn[x - 1];
			if (latestchar == ';')
			{
				if (next == ';' && previous != ' ' && previous != ';')
				{
					new_lyn[y++] = ' ';
					new_lyn[y++] = ';';
					continue;
				}
				else if (previous == ';' && next != ' ')
				{
					new_lyn[y++] = ';';
					new_lyn[y++] = ' ';
					continue;
				}
				if (previous != ' ')
					new_lyn[y++] = ' ';
				new_lyn[y++] = ';';
				if (next != ' ')
					new_lyn[y++] = ' ';
				continue;
			}
			else if (latestchar == '&')
			{
				if (next == '&' && previous != ' ')
					new_lyn[y++] = ' ';
				else if (previous == '&' && next != ' ')
				{
					new_lyn[y++] = '&';
					new_lyn[y++] = ' ';
					continue;
				}
			}
			else if (latestchar == '|')
			{
				if (next == '|' && previous != ' ')
					new_lyn[y++]  = ' ';
				else if (previous == '|' && next != ' ')
				{
					new_lyn[y++] = '|';
					new_lyn[y++] = ' ';
					continue;
				}
			}
		}
		else if (latestchar == ';')
		{
			if (x != 0 && old_lyn[x - 1] != ' ')
				new_lyn[y++] = ' ';
			new_lyn[y++] = ';';
			if (next != ' ' && next != ';')
				new_lyn[y++] = ' ';
			continue;
		}
		new_lyn[y++] = old_lyn[x];
		x++;
	}
	new_lyn[y] = '\0';

	free(*lyn);
	*lyn = new_lyn;
}

