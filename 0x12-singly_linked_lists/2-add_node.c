#include "lists.h"

/**
 * add_note - adds a new node at the beginging of a linked list.
 *
 * @head: double pointer to the list_t list.
 * @str: new string to be added in the list_t list.
 *
 * Return: if memory allocation or string duplication fails - NULL.
 * Otehrwise - the address of the new node.
 */

list_t *add_node(list_t **head, const char *str)
{
	char *str_duplicate;
	int str_len;
	list_t *new_node;

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
	new_node->next = *head;

	*head = new_node;

	return (new_node);
}
