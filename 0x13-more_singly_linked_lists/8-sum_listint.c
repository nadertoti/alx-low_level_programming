#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n) in a linked list.
 * @head: A pointer to the head of the list.
 *
 * Return: The sum of all data values, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
    int sum;

    sum = 0;

    if (head == NULL)
        return (0);

    while (head != NULL)
    {
        sum += head->n;
        head = head->next;
    }

    return (sum);
}
