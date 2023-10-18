#include "shell.h"

/**
 * put_endnode - This functions adds  node to the end of a  linked list.
 * @head: A pointer to the head of the  list
 * @path: The directory path for the new node
 * Return: endnode) on success
 */
lynkd_lst *put_endnode(lynkd_lst **head, char *path)
{
	lynkd_lst *tm;
	lynkd_lst *endnode;

	endnode = malloc(sizeof(*endnode));
	if (!endnode)
		return (NULL);

	endnode->dir = path;
	endnode->next = NULL;

	if (*head)
	{
		tm = *head;
		while (tm->next != NULL)
			tm = tm->next;
		tm->next = endnode;
	}
	else
		*head = endnode;

	return (endnode);
}

