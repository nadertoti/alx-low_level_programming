#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a list
 *
 * @head: pointer to head node
 * @n: integer
 *
 * Return: address of the new element,
 * NULL if it failed
 *
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *nodes;

	nodes = malloc(sizeof(listint_t));
	if (!nodes)
		return (NULL);
	nodes->n = n;
	nodes->next = *head;
	*head = nodes;

	return (nodes);
}
