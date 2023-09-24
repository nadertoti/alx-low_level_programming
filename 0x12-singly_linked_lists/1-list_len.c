#include "lists.h"

/**
 * list_len - Counts the number of elements in a linked list.
 *
 * @head: A pointer to the head of the list.
 *
 * Return: The number of elements in the list.
 */
size_t list_len(const list_t *head)
{
    size_t count = 0;

    while (head != NULL)
    {
        head = head->next;
        count++;
    }

    return (count);
}
