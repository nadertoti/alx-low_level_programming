#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a linked list.
 * @head: A pointer to the head of the list.
 * @index: Index of the node to retrieve.
 *
 * Return: Address of the node at the given index, or NULL if not found.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int n;

	n = 0;
	while (n < index)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
		n++;
	}
	return (head);
}
