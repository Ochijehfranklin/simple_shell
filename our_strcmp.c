#include "shell.h"

/**
 * our_strcmp - This function would compare two strings for us
 * @str1: first string
 * @str2: second string
 * Return: Success (0)
 */

int our_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);

	return (0);
}
