#include "lists.h"

/**
 * list_len - returns the number elements of a linked list_t list.
 * @h: pointer to the head of the list.
 *
 * Return: The number of elements in the list.
 */

size_t list_len(const list_t *h)
{
	size_t nodecount = 0;

	while (h)
	{
		nodecount++;
		h = h->next;
	}

	return (nodecount);
}
