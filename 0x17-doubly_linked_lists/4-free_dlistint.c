#include "lists.h"

/**
 * free_dlistint - free the list
 * @head: address of the head of the list
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *node;

	while (head)
	{
		node = head;
		head = head->next;
		free(node);
	}
}
