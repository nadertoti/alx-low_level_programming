#include "lists.h"

/**
 * sum_dlistint - sum of values
 * @head: address of the head of the list
 *
 * Return: int
 */
int sum_dlistint(dlistint_t *head)
{
	int Total = 0;

	while (head)
	{
		Total += head->n;
		head = head->next;
	}
	return (Total);
}
