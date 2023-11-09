#include "lists.h"

/**                                                                       
 * dlistint_len - returns the number of elements in a doubly-linked list  
 * @head: address of the head of the list                                 
 * @h: int for the list                                                   
 * Return: size of the list                                               
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
        dlistint_t *new = malloc(sizeof(dlistint_t));

        if (!head || !new)
          return (new ? free(new), NULL : NULL);

        new->n = n;
        new->prev = NULL;
        if (!*head)
        {
                *head = new;
                new->next = NULL;
        }
        else
        {
                new->next = *head;
                (*head)->prev = new;
                *head = new;
        }
        return (new);
} 
