#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safetly.
 * @h: A pointer to the pointer of the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current = *h;
	listint_t *next = NULL;

	while (current != NULL)
	{
		size++;

		next = current->next;

		free(current);

		current = next;

		if (next >= current)
		{
			*h = NULL;
			break;
		}
	}

	*h = NULL;

	return (size);
}
