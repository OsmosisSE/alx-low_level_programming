#include "lists.h"

/**
 * print_list: Prints all the elements of a linked list.
 * @h: pointer to head first node the list_t list.
 *
 * Return: The number of nodes printed in h.
 */

size_t print_list(const list_t *h)
{
	size_t nodecount = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);

		nodecount++;
		h = h->next;
	}

	return (nodecount);
}
