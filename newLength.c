#include "shell.h"

/**
 * newLength - gets the newLength of line if divided by "&&", "||", "#", ";"
 * @lyn: to obtain the length of line
 * Return: the new lwngth of line
 */
ssize_t newLength(char *lyn)
{
	size_t x;
	char cur, nxt;
	ssize_t new_length = 0;

	x = 0;
	while (lyn[x])
	{
		cur = lyn[x];
		nxt = lyn[x + 1];
		if (cur == '#')
		{
			if (x == 0 || lyn[x - 1] == ' ')
			{
				lyn[x] = '\0';
				break;
			}
		}
		else if (x != 0)
		{
			if (cur == ';')
			{
				if (nxt == ';' && lyn[x - 1] != ' ' && lyn[x - 1] != ';')
				{
					new_length += 2;
					continue;
				}
				else if (lyn[x - 1] == ';' && nxt != ' ')
				{
					new_length += 2;
					continue;
				}
				if (lyn[x - 1] != ' ')
					new_length++;
				if (nxt != ' ')
					new_length++;
			}
			else
				op_check(&lyn[x], &new_length);
		}
		else if (cur == ';')
		{
			if (x != 0 && lyn[x - 1] != ' ')
				new_length++;
			if (nxt != ' ' && nxt != ';')
				new_length++;
		}
		new_length++;
		x++;
	}
	return (new_length);
}
