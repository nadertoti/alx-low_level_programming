#include "lists.h"

/**
 * print_listint - prints all the elements of a list
 *
 * @head: pointer to head node
 *
 * Return: the number of nodes
 *
 */
size_t print_listint(const listint_t *head)
{
	size_t sum;

	sum = 0;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		sum++;
	}
	return (sum);
}
