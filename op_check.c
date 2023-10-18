#include "shell.h"

/**
 * op_check - This function checks a line for operators like "||" or "&&"
 * @lyn: the charcater to check the line
 * @new_length: points to the new_length
 */
void op_check(char *lyn, ssize_t *new_length)
{
	char prev, cur, nxt;

	prev = *(lyn - 1);
	cur = *lyn;
	nxt = *(lyn + 1);

	if (cur == '&')
	{
		if (nxt == '&' && prev != ' ')
			(*new_length)++;
		else if (prev == '&' && nxt != ' ')
			(*new_length)++;
	}
	else if (cur == '|')
	{
		if (nxt == '|' && prev != ' ')
			(*new_length)++;
		else if (prev == '|' && nxt != ' ')
			(*new_length)++;
	}
}
