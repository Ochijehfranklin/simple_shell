#include "shell.h"
/**
 * our_getline - This function reads input from stream
 * @linept: to store typed command
 * @m: size of pointer
 * @streem: stream to read
 * Return: returns the file read on success
 */
ssize_t our_getline(char **linept, size_t *m, FILE *streem)
{
	int x;
	char tem = 'A', *buffer;
	ssize_t byte;
	static ssize_t typed;

	if (typed == 0)
		fflush(streem);
	else
		return (-1);
	typed = 0;
	buffer = malloc(sizeof(*buffer) * 120);
	if (!buffer)
		return (-1);
	while (tem != '\n')
	{
		x = read(STDIN_FILENO, &tem, 1);
		if (x == -1 || (x == 0 && typed == 0))
		{
			free(buffer);
			return (-1);
		}
		if (x == 0 && typed != 0)
		{
			typed++;
			break;
		}
		if (typed >= 120)
			buffer = our_realloc(buffer, typed, typed + 1);
		buffer[typed] = tem;
		typed++;
	}
	buffer[typed] = '\0';
	our_setlineptr(linept, m, buffer, typed);
	byte = typed;
	if (x != 0)
		typed = 0;
	return (byte);
}
