#include "lists.h"

/**
 * add_node_end - Adds a new node to the end of a list.
 * @head: A pointer to the list's head.
 * @str: The string to be added to the list.
 *
 * Return: if memory allocation or string duplication fails - NULL.
 * Otherwise - the address of the new node.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	char *str_duplicate;
	int str_len;
	list_t *new_node, *last_node;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	str_duplicate = strdup(str);
	if (str_duplicate == NULL)
	{
		free(new_node);
		return (NULL);
	}

	str_len = 0;
	while (str[str_len])
		str_len++;

	new_node->str = str_duplicate;
	new_node->len = str_len;
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;

	else
	{
		last_node = *head;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}

	return (*head);
}
