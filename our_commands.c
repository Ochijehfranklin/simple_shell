#include "shell.h"

/**
 * our_commands - This function takes care of runing file commands
 * @pat: This is the path to the file
 * @last_retrn: The return value of last command executed
 * Return: The command
 */
int our_commands(char *pat, int *last_retrn)
{
	int retur_val;
	char *lyn, **args, **arg0, buffer[128];
	ssize_t files, byte, x;
	unsigned int lyn_size = 0, past_size = 128;

	cmdhist = 0;
	files = open(pat, O_RDONLY);
	if (files == -1)
	{
		*last_retrn = fopen_error(pat);
		return (*last_retrn);
	}
	lyn = malloc(sizeof(char) * past_size);
	if (!lyn)
		return (-1);
	do {
		byte = read(files, buffer, 127);
		if (byte == 0 && lyn_size == 0)
			return (*last_retrn);
		buffer[byte] = '\0';
		lyn_size += byte;
		lyn = our_realloc(lyn, past_size, lyn_size);
		our_strcat(lyn, buffer);
		past_size = lyn_size;
	} while (byte);
	x = 0;
	while (lyn[x] == '\n')
	{
		lyn[x] = ' ';
		x++;
	}
	while (x < lyn_size)
	{
		if (lyn[x] == '\n')
		{
			lyn[x] = ';';
			for (x += 1; x < lyn_size && lyn[x] == '\n'; x++)
				lyn[x] = ' ';
		}
		x++;
	}
	change_var(&lyn, last_retrn);
	break_line(&lyn, lyn_size);
	args = our_strtok(lyn, " ");
	free(lyn);
	if (!args)
		return (0);
	if (look_args(args) != 0)
	{
		*last_retrn = 2;
		fri_args(args, args);
		return (*last_retrn);
	}
	arg0 = args;
	x = 0;
	while (args[x])
	{
		if (our_strncmp(args[x], ";", 1) == 0)
		{
			free(args[x]);
			args[x] = NULL;
			retur_val = kal_args(args, arg0, last_retrn);
			args = &args[++x];
			x = 0;
		}
		x++;
	}
	retur_val = kal_args(args, arg0, last_retrn);

	free(arg0);
	return (retur_val);
}
