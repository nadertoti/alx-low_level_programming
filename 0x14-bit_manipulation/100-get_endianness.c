#include "main.h"

/**
 * get_endianness - Check the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *byte = (char *)&num;

 
	if (*byte)
		return (1);

	else
		return (0);
}
