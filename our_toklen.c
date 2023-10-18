#include "shell.h"

/**
 * our_toklen - This function finds a sign that ends a string
 * @string: the string
 * @delem: The separator
 * Return: the length of the token
 */
int our_toklen(char *string, char *delem)
{
	int x, length;

	x = 0;
	length = 0;
	while (*(string + x) && *(string + x) != *delem)
	{
		length++;
		x++;
	}
	return (length);
}
