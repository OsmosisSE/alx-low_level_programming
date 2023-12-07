#include "lists.h"

/**
 * free_dlistint - Frees a dounly-linked list of integers.
 * @head: A pointer to the head of the doubly-linked list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *courrent_nodes, *next_nodes;

	while (head)
	{
		next_nodes = head->next;
		free(head);
		head = next_nodes;
	}
}
