#include "main.h"

/**
 * flip_bits - Calculate the number of differing bits between two numbers.
 * @n: The first unsigned long integer.
 * @m: The second unsigned long integer.
 *
 * Return: The number of differing bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int difference = n ^ m;
	unsigned int count = 0;

	while (difference)
	{
		if (difference & 1)
			count++;
		difference = difference >> 1;
	}
	return (count);
}
