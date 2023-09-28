#include "main.h"

/**
 * flip_bits - Calculate the number of bits needed to flip from one number
 *             to another.
 * @n: The first unsigned long integer.
 * @m: The second unsigned long integer.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff = n ^ m;
	unsigned int count = 0;

	while (diff > 0)
	{
		count += diff & 1; /* Check the least significant bit */
		diff >>= 1;       /* Right-shift to examine the next bit */
	}

	return count;
}
