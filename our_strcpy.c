#include "shell.h"

/**
 * our_strcpy - Copy a string to a destination buffer
 * @buffer_dest: Destination buffer to copy string into
 * @src: Source string to copy from into dest
 * Return: copied string
 */
char *our_strcpy(char *buffer_dest, const char *src)
{
	size_t length = 0;


	if (src == NULL || buffer_dest == NULL)
	{
		return (0);
	}


	while (src[length] != '\0')
	{
		buffer_dest[length] = src[length];
		length++;
	}


	buffer_dest[length] = '\0';
	return (buffer_dest);
}

