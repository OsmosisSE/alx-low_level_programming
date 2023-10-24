#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *temp_n = NULL;
	const listint_t *l_n = NULL;
	size_t counter = 0;
	size_t new_nd;

	temp_n = head;
	while (temp_n)
	{
		printf("[%p] %d\n", (void *)temp_n, temp_n->n);
		counter++;
		temp_n = temp_n->next;
		l_n = head;
		new_nd = 0;
		while (new_nd < counter)
		{
			if (temp_n == l_n)
			{
				printf("[%p] %d\n", (void *)temp_n, temp_n->n);
				return (counter);
			}
			l_n = l_n->next;
			new_nd++;
		}
		if (!head)
			exit(98);
	}
	return (counter);
}
