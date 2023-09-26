#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given position in a list.
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index of the node to be deleted (index starts at 0).
 *
 * Return: 1 if the deletion succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *previous;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}

	previous = NULL;
	for (i = 0; i < index; i++)
	{
		if (current == NULL)
			return (-1);
		previous = current;
		current = current->next;
	}

	if (current == NULL)
		return (-1);

	previous->next = current->next;
	free(current);

	return (1);
}
