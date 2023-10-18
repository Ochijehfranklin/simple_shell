#include "shell.h"

/**
 * our_strtok - This function would tokenize a string
 * @str: string to tokenize
 * @delem: the deparator that would be needed to separate string
 * Return: tokenized string
 */
char **our_strtok(char *str, char *delem)
{

	int x, toks, y, alpha, z;
	char **pt;

	x = 0;
	toks = our_tokcount(str, delem);
	if (toks == 0)
		return (NULL);
	pt = malloc(sizeof(char *) * (toks + 2));
	if (!pt)
		return (NULL);
	y = 0;
	while (y < toks)
	{
		while (str[x] == *delem)
			x++;
		alpha = our_toklen(str + x, delem);
		pt[y] = malloc(sizeof(char) * (alpha + 1));
		if (!pt[y])
		{
			for (x -= 1; x >= 0; x--)
				free(pt[x]);
			free(pt);
			return (NULL);
		}
		z = 0;
		while (z < alpha)
		{
			pt[y][z] = str[x];
			x++;
			z++;
		}
		pt[y][z] = '\0';
		y++;
	}
	pt[y] = NULL;
	pt[y + 1] = NULL;
	return (pt);
}
