#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new code at a given position.
 * @head: A pointer to the pointer of the head of the listint_t list.
 * @idx: The index where the new node should be added, starting at 0.
 * @n: The integer value to be added to the new node.
 *
 * Return: The address of the new node or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_nd, *current, *previous;
	unsigned int i = 0;

	new_nd = malloc(sizeof(listint_t));

	if (new_nd == NULL)
	{
		return (NULL);
	}

	new_nd->n = n;
	current = *head;

	if (idx == 0)
	{
		new_nd->next = current;
		*head = new_nd;
		return (new_nd);
	}

	while (i < idx && current != NULL)
	{
		previous = current;
		current = current->next;
		i++;
	}

	if (i == idx)
	{
		previous->next = new_nd;
		new_nd->next = current;
		return (new_nd);
	}

	free(new_nd);
	return (NULL);
}
