#include "main.h"

/**
 * set_bit - Set the value of a bit to 1 at a given index.
 * @n: Pointer to the unsigned long integer to modify.
 * @index: The index of the bit to set (0-based).
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1); /* Invalid index */
	}

	*n |= (1 << index); /* Set the bit at index to 1 */
	return (1);
}
