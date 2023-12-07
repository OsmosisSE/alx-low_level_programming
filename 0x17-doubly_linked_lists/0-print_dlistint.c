#include "lists.h"

/**
 * print_dlistint - Prints all elements in a doubly-linked list.
 * @head: The head of the doubly-linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *head)
{
	size_t node_count = 0;

	while (head)
	{
		node_count++;
		printf("%d\n", head->n);
		head = head->next;
	}

	return (node_count);
}
