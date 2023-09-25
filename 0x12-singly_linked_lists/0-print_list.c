#include "lists.h"

/**
 * print_list - print all the elements of a list
 *
 * @head: head
 *
 * Return: number of nodes
 *
 */
size_t print_list(const list_t *head)
{
	size_t sum;

	sum = 0;
	while (head != NULL)
	{
		if (head->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", head->len, head->str);
		n++;
		head = head->next;
	}
	return (sum);
}
