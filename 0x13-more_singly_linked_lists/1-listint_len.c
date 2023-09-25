#include "lists.h"

/**
 * listint_len - returns the number of elements
 * in a linked list
 *
 * @head: pointer to head node
 *
 * Return: number of elements
 *
 */
size_t listint_len(const listint_t *head)
{
	size_t sum;

	sum = 0;
	while (head)
	{
		head = head->next;
		sum++;
	}
	return (sum);
}
