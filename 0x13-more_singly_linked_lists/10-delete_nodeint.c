#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index.
 * @head: A pointer to the pointer of the head of the listint_t list.
 * @index: The index of the node to the deleted, starting at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *previous;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (i);
	}

	while (i < index && current != NULL)
	{
		previous = current;
		current = current->next;
		i++;
	}

	if (i == index)
	{
		previous->next = current->next;
		free(current);
		return (1);
	}

	return (-1);
}
