#include "lists.h"

/**
 * free_dlistint - Frees a dounly-linked list of integers.
 * @head: A pointer to the head of the doubly-linked list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
