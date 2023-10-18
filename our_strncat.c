#include "shell.h"

/**
 * our_strncat - This function joins a specified byte of string
 * @s1: The string to which another would be joined
 * @s2: The string to be joined
 * @m: The bytes of string to copy from s2
 * Return: The joined string
 */
char *our_strncat(char *s1, const char *s2, size_t m)
{
	size_t s1Len = our_strlength(s1);
	size_t x;

	x = 0;
	while (x < m && s2[x] != '\0')
	{
		s1[s1Len + x] = s2[x];
		x++;
	}
	s1[s1Len + x] = '\0';
	return (s1);
}
