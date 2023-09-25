#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list using Floyd's Algorithm.
 * @head: A pointer to the head of the list.
 *
 * Return: The address of the node where the loop starts, or NULL if there's no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
    listint_t *slow = head;
    listint_t *fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;          /* Move one step at a time */
        fast = fast->next->next;    /* Move two steps at a time */

        if (slow == fast) /* Loop detected */
        {
            /* Move one pointer to the head and continue at the same pace */
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return (slow); /* Return the starting node of the loop */
        }
    }

    return (NULL); /* No loop found */
}
