#include "shell.h"

/**
 * ret_path - This function would split colon-separated list of directories
 * @path: colon-separated list directories
 * Return: linked list
 */
lynkd_lst *ret_path(char *path)
{
	char **dirs, *pathup;
	int x;
	lynkd_lst *heads = NULL;

	pathup = path_populate(path);

	if (!pathup)
		return (NULL);
	dirs = our_strtok(pathup, ":");
	free(pathup);
	if (!dirs)
		return (NULL);
	x = 0;
	while (dirs[x])
	{
		if (put_endnode(&heads, dirs[x]) == NULL)
		{
			fri_list(heads);
			free(dirs);
			return (NULL);
		}
		x++;
	}
	free(dirs);

	return (heads);
}
