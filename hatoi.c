#include "shell.h"

/**
 * hatoi - This acts like atoi function
 * @m: integer to be converted
 * Return: converted string
 */
char *hatoi(int m)
{
	unsigned int length;
	unsigned int digit;
	unsigned int buffer;
	char *string;

	length = length_int(m);
	buffer = length + 1;

	string = malloc(sizeof(*string) * (buffer + 1));
	if (!string)
		return (NULL);
	if (m < 0)
	{
		digit = m * -1;
		string[0] = '-';
	}
	else
	{
		digit = m;
	}
	while (digit > 0)
	{
		string[length] = (digit % 10) + '0';
		digit /= 10;
		length--;
	}
	string[buffer] = '\0';
	return (string);
}
