#include "lists.h"

/**
 * free_list - Free a linked list along with its data.
 * @head: A pointer to the head of the list to be freed.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
