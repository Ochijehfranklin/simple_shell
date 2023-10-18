#include "shell.h"
/*****INITIALIZE THE SHELL*******/
/**
 * main - This is our entry point fot the shell project
 * @arc: This counts the number of arguments
 * @argv: The holder for our arguments
 * Return: Always success (0)
 */
int main(int arc, char **argv)
{
	char *request = "Goshell ", *freshline = "\n";
	int retrn_val, exc_ret;
	int *retrn = &exc_ret;

	cmdhist = 1;
	retrn_val = 0;
	nam = argv[0];
	signal(SIGINT, mg_sig);
	*retrn = 0;
	environ = our_envcopy();
	if (!environ)
		exit(-100);
	if (arc != 1)
	{
		retrn_val = our_commands(argv[1], retrn);
		fri_env();
		return (*retrn);
	}
	if (!isatty(STDIN_FILENO))
	{
		while (retrn_val != my_EOF && retrn_val != EXIT)
			retrn_val = mg_args(retrn);
		fri_env();
		return (*retrn);
	}
	while (true)
	{
		write(STDOUT_FILENO, request, 8);
		retrn_val = mg_args(retrn);
		if (retrn_val == my_EOF || retrn_val == EXIT)
		{
			if (retrn_val == my_EOF)
				write(STDOUT_FILENO, freshline, 1);
			fri_env();
			exit(*retrn);
		}
	}
	fri_env();
	return (*retrn);
}
