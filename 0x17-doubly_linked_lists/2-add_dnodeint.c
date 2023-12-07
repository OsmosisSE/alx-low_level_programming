#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the begining of doubly-linked list.
 * @head: A pointer to the head of the doubly-linked list.
 * @n: The integer value for the new node.
 *
 * Return: If the function fails- NULL, Otherwise- the address of the new node.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}
