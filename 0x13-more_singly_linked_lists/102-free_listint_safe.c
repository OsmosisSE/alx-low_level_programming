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
	int diff;
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		diff = *h - (*h)->next;
		if (diff > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			size++;
		}
		else
		{
			free(*h);
			*h = NULL;
			size++;
			break;
		}
	}

	*h = NULL;

	return (size);
}
