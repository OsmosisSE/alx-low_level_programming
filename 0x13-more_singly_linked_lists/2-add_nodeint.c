#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a listint_t list.
 * @head: A pointer to the pointer of the head of the listint_t list.
 * @n: The integer value to be added to the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_nd;

	new_nd = malloc(sizeof(listint_t));

	if (new_nd == NULL)
	{
		return (NULL);
	}

	new_nd->n = n;
	new_nd->next = *head;
	*head = new_nd;

	return (new_nd);
}
