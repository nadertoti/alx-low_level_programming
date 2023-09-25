#include "lists.h"

/**
 * free_list - fress a list in memory
 *
 * @head: head of the linked list
 *
 */
void free_list(list_t *head)
{
	list_t *first_node = head;
	list_t *next_node;

	while (first_node)
	{
		next_node = first_node->next_node;
		free(first_node->str);
		free(first_node);
		first_node = next_node;
	}
	head = NULL;
}
