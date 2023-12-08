#include "lists.h"

/**
 * sum_dlistint - Sums all the data in a doubly-linked list of integers.
 * @head: A pointer to the head of the doubly-linked list.
 *
 * Return: The sum of all the data.
 */
int sum_dlistint(dlistint_t *head)
{
	int total_sum = 0;

	while (head)
	{
		total_sum += head->n;
		head = head->next;
	}

	return (total_sum);
}
