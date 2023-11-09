#include "lists.h"

/**
 * get_dnodeint_at_index - get the node at a specific index
 * @head: address of the head of the list
 * @index: index of the node to retrieve
 *
 * Return: pointer to the node at the specified index, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int j = 0;

	while (head)
	{
		if (j == index)
			return (head);
		head = head->next;
		j++;
	}
	return (NULL);
}
