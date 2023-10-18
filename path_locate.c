#include "shell.h"

/**
 * path_locate - This function locates a command in PATH
 * @cmds: command to locate
 * Return: full path
 */
char *path_locate(char *cmds)
{
	struct stat st;
	char **path, *tm;
	lynkd_lst *dirs, *head;

	path = get_env("PATH");
	if (!path || !(*path))
		return (NULL);
	dirs = ret_path(*path + 5);
	head = dirs;
	while (dirs)
	{
		tm = malloc(our_strlength(dirs->dir) + our_strlength(cmds) + 2);
		if (!tm)
			return (NULL);
		our_strcpy(tm, dirs->dir);
		our_strcat(tm, "/");
		our_strcat(tm, cmds);
		if (stat(tm, &st) == 0)
		{
			fri_list(head);
			return (tm);
		}
		dirs = dirs->next;
		free(tm);
	}
	fri_list(head);

	return (NULL);
}
