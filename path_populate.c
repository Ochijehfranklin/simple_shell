#include "shell.h"

/**
 * path_populate - This function would copy
 * and replace leading colons with curr direct
 * @path: This is for Colon-separated list of directories
 * Return: duplicate of path
 */
char *path_populate(char *path)
{
	char *pathup, *pwd;
	int x, length;

	pwd = *(get_env("PWD")) + 4;
	length = 0;
	x = 0;
	while (path[x])
	{
		if (path[x] == ':')
		{
			if (path[x + 1] == ':' || x == 0 || path[x + 1] == '\0')
				length += our_strlength(pwd) + 1;
			else
				length++;
		}
		else
			length++;
		x++;
	}
	pathup = malloc(sizeof(*pathup) * (length + 1));
	if (!pathup)
		return (NULL);
	pathup[0] = '\0';
	x = 0;
	while (path[x])
	{
		if (path[x] == ':')
		{
			if (x == 0)
			{
				our_strcat(pathup, pwd);
				our_strcat(pathup, ":");
			}
			else if (path[x + 1] == ':' || path[x + 1] == '\0')
			{
				our_strcat(pathup, ":");
				our_strcat(pathup, pwd);
			}
			else
				our_strcat(pathup, ":");
		}
		else
			our_strncat(pathup, &path[x], 1);
		x++;
	}
	return (pathup);
}
