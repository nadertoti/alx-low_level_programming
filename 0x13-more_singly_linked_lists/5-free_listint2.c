#include "lists.h"

/**
 * free_listint2 - Frees a linked list of integers and sets the head to NULL.
 * @head: A pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
    listint_t *temp;

    if (head == NULL || *head == NULL)
        return;

    while (*head != NULL)
    {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}
