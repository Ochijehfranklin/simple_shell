#include "shell.h"


/**
 * mg_sig - signal manager for the clearing of screen
 * @sign: signal passed
 */
void mg_sig(int sign __attribute__((unused)))
{
	char *request = "\nGoshell ";


	signal(SIGINT, mg_sig);
	write(STDIN_FILENO, request, 10);
}

