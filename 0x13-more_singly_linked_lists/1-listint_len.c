#include "lists.h"

/**
 * listint_len - REturns the number of elements in a listint_t list.
 * @h: A pointer to the head of the listint_t list.
 *
 * Return: The number of elements in the list.
 */
size_t listint_len(const listint_t *h)
{
	size_t nd_count = 0;

	while (h != NULL)
	{
		nd_count++;
		h = h->next;
	}

	return (nd_count);
}
