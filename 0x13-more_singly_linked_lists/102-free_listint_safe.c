#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *current = *h;
    size_t size = 0;
    listint_t *temp = NULL;

    while (current != NULL)
    {
        size++;
        temp = current;
        current = current->next;
        free(temp);

        if (temp <= current)
        {
            *h = NULL; /* Set the head to NULL */
            break;
        }
    }

    return (size);
}
