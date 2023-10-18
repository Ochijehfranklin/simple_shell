#include "shell.h"

/**
 * our_setlineptr - This would re-assign linept for our_getline function
 * @linept: store the typed string
 * @m: scale of linept
 * @buffer: string assigned to linept
 * @c: buffer size
 */
void our_setlineptr(char **linept, size_t *m, char *buffer, size_t c)
{
	if (*linept == NULL)
	{
		if (c > 120)
			*m = c;
		else
			*m = 120;
		*linept = buffer;
	}
	else if (*m < c)
	{
		if (c > 120)
			*m = c;
		else
			*m = 120;
		*linept = buffer;
	}
	else
	{
		our_strcpy(*linept, buffer);
		free(buffer);
	}
}

