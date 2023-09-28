#include "main.h"

/**
 * print_binary - Print the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned int shift = sizeof(n) * 8 - 1;

	while (shift > 0)
	{
		_putchar((n >> shift) & 1 ? '1' : '0');
		shift--;
	}

	_putchar((n & 1) ? '1' : '0');
}
