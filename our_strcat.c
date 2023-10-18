#include "shell.h"

/**
 * our_strcat - This function joins strings together
 * @s1: string to which we join another to
 * @s2: string to be joined to s1
 * Return: The joined string
 */

char *our_strcat(char *s1, const char *s2)
{
	int x;
	int s1Len = our_strlength(s1);

	x = 0;
	while (s2[x] != '\0')
	{
		s1[s1Len + x] = s2[x];
		x++;
	}
	s1[s1Len + x] = '\0';
	return (s1);
}
