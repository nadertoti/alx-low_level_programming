#include "lists.h"

/**
 * free_listint - Frees a linked list of integers.
 * @head: A pointer to the head of the list.
 */
void free_listint(listint_t *head)
{
    listint_t *temp;

    while (head != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}
