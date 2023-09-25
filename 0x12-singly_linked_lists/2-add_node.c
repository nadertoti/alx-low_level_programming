#include "lists.h"

/**
 * add_node - adds a new node at the beginnning of a list
 *
 * @head: head
 * @str: string
 *
 * Return: the address of the new element, else
 * NULL if it failed
 *
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *nodes;
	char *strings;

	nodes = malloc(sizeof(list_t));
	if (nodes == NULL)
		return (NULL);
	strings = strdup(str);
	nodes->str = strings;
	if (!(nodes->str))
	{
		free(nodes);
		return (NULL);
	}
	nodes->len = strlen(nodes->str);
	nodes->next = *head;
	*head = nodes;

	return (nodes);
}
