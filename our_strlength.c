#include "shell.h"


/*****RETURN LENGTH OF STRING*/
/**
 * our_strlength - function to return the length of string
 * @format: string whose length we are to print
 * Return: The length of string
 */


int our_strlength(const char *format)


{
	int len = 0;


	if (!format)
	{
		return (len);
	}
	len = 0;
	while (format[len])
	{
		len++;
	}
	return (len);
}

