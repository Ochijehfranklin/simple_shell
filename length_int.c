#include "shell.h"


/**
 * length_int - This function counts length of a digit
 * @m: The digits to count
 * Return: digit length
 */
int length_int(int m)
{
	int digits;
	int length;

	length = 0;

	if (m < 0)
	{
		length++;
		digits = m * -1;
	}
	else
	{
		digits = m;
	}
	while (digits > 9)
	{
		length++;
		digits /= 10;
	}
	return (length);
}

