#include <stddef.h>  /* Include this first */
#include "main.h"    /* Include your custom header */

/**
 * binary_to_uint - Convert a binary string to an unsigned int.
 * @b: Pointer to the binary string.
 *
 * Return: The converted unsigned int, or 0 if an invalid character is found
 *         or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;

    if (b == NULL)
        return 0;

    while (*b)
    {
        if (*b != '0' && *b != '1')
            return 0; /* Invalid character found, return 0 */

        result = (result << 1) | (*b - '0'); /* Convert binary to integer */
        b++;
    }

    return result;
}
