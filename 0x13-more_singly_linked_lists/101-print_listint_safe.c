#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);

		count++;

		if (head >= head->next)
		{
			fprintf(stderr, "Error: Bad loop detected\n");
			exit(98);
		}

		head = head->next;
	}

	return (count);
}
