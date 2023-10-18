#include "shell.h"

/**
 * fri_list - This function frees a list_path linked list
 * @head: head of the list
 */
void fri_list(lynkd_lst *head)
{
	lynkd_lst *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}
