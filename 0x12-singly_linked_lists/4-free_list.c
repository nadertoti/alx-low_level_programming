#include "lists.h"

/**
 * free_list - fress a list
 *
 * @head: head
 *
 */
void free_list(list_t *head)
{
	list_t *sum = head;
	list_t *nextnode;

	while (sum)
	{
		nextnode = sum->nextnode;
		free(sum->str);
		free(sum);
		sum = nextnode;
	}
	head = NULL;
}
