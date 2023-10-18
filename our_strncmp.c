#include "shell.h"

/**
 * our_strncmp - This function compares a specific byte of strings
 * @str1: first string to be compared with second
 * @str2: second string to be compared with first
 * @m: bytes of strings to compare
 * Return: negative index
 * if str1 < str2, 0 if str1 == str2, above 0 if str1 > str2
 */
int our_strncmp(const char *str1, const char *str2, size_t m)
{
	size_t x;

	x = 0;
	while (str1[x] && str2[x] && x < m)
	{
		if (str1[x] > str2[x])
			return (str1[x] - str2[x]);
		else if (str1[x] < str2[x])
			return (str1[x] - str2[x]);
		x++;
	}
	if (x == m)
		return (0);
	else
		return (-15);
}
