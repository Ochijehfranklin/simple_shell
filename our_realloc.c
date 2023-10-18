#include "shell.h"

/**
 * our_realloc - this function reallocates mem
 * @prevptr: this points to the previous memory allocation
 * @old_block: points to the size in bytes allocated to prevptr
 * @new_block: points to size in bytes allocated to a new memory block
 * Return: returns pointer to the new mem
 */
void *our_realloc(void *prevptr, unsigned int old_block,
		unsigned int new_block)
{
	char *ptrup, *bufer;
	unsigned int x;
	void *latestmem;

	if (new_block == old_block)
		return (prevptr);
	if (prevptr == NULL)
	{
		latestmem = malloc(new_block);
		if (latestmem == NULL)
			return (NULL);
		return (latestmem);
	}
	if (new_block == 0 && prevptr != NULL)
	{
		free(prevptr);
		return (NULL);
	}
	ptrup = prevptr;
	latestmem = malloc(sizeof(*ptrup) * new_block);
	if (latestmem == NULL)
	{
		free(prevptr);
		return (NULL);
	}
	bufer = latestmem;
	x = 0;
	while (x < old_block && x < new_block)
	{
		bufer[x] = *ptrup++;
		x++;
	}
	free(prevptr);
	return (latestmem);
}
