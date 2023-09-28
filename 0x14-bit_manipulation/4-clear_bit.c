#include "main.h"

/**
 * clear_bit - Clear (set to 0) the value of a bit at a given index.
 * @n: Pointer to the unsigned long integer to modify.
 * @index: The index of the bit to clear (0-based).
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1); /* Invalid index */
	}

	*n &= ~(1 << index); /* Clear the bit at index */
	return (1);
}
