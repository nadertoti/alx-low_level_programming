#include "main.h"

/**
 * print_binary - Print the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
    int shift;
    int flag = 0;

    for (shift = sizeof(n) * 8 - 1; shift >= 0; shift--)
    {
        if ((n >> shift) & 1)
        {
            _putchar('1');
            flag = 1;
        }
        else if (flag || shift == 0)
        {
            _putchar('0');
        }
    }
}
