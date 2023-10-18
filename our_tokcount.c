#include "shell.h"

/**
 * our_tokcount - this function would count
 * the number of separations in a string
 * @string: a string to count
 * @delem: the separator
 * Return: number of tokens counted
 */
int our_tokcount(char *string, char *delem)
{
	int x, toks, length;

	x = 0;
	length = 0;
	toks = 0;
	while (*(string + x))
	{
		length++;
		x++;
	}

	x = 0;
	while (x < length)
	{
		if (*(string + x) != *delem)
		{
			toks++;
			x += our_toklen(string + x, delem);
		}
		x++;
	}
	return (toks);
}
