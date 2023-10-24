#include "lists.h"

/**
 * free_listints2 - Frees a listint_t list and sets the head to NULL.
 * @head: A pointer to the pointer of the head of the listint_t list.
 */
void free_listints2(listint_t **head)
{
	listint_t *temp, *c;

	c = *head;

	while (c != NULL)
	{
		temp = c;
		c = c->next;
		free(temp);
	}

	*head = NULL;
}
