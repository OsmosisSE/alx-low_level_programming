#include "lists.h"

/**
 * dlistint_len - Counts the number of elements in a doubly-linked list.
 * @head: The head of the doubly-linked list.
 *
 * Return: The number of elements in the doubly-linked list.
 */
size_t dlistint_len(const dlistint_t *head)
{
	size_t nodes_count = 0;

	while (head)
	{
		nodes_count++;
		head = head->next;
	}

	return (nodes_count);
}
