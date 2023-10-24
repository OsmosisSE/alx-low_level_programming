#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 * @head: A pointer to the pointer of the head of the listint_t list.
 *
 * Description: Sets the head to NULL.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp, *current;

	current = *head;


	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}

	*head = NULL;
}
