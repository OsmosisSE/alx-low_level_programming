#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint- converts a binary number to unsinged int
 * @b: string containing the binary number
 * Return: The converterd number.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	unsigned int power = 1;
	int l;

	if (b == NULL)
		return (0);

	for (l = 0; b[l]; l++)
	{
		if (b[l] != '0' && b[l] != '1')
			return (0);
	}

	for (l--; l >= 0; l--)
	{
		if (b[l] == '1')
			result += power;
		power *= 2;
	}

	return (result);
}
