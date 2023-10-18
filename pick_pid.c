#include "shell.h"

/**
 *pick_pid - this function gets current ID of our shell
 * Return: the cureent id
 */
char *pick_pid(void)
{
	char *pid;
	size_t x;
	ssize_t files;

	x = 0;
	files = open("/proc/self/stat", O_RDONLY);
	if (files == -1)
	{
		perror("Can't read the file");
		return (NULL);
	}
	pid = malloc(128);
	if (!pid)
	{
		close(files);
		return (NULL);
	}
	read(files, pid, 128);
	while (pid[x] != ' ')
		x++;
	pid[x] = '\0';
	close(files);

	return (pid);
}

