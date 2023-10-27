#include "main.h"

/**
 * flip_bits - coounts the number of bits needed to be flipped
 * @n: The number.
 * @m: The number to flip n to.
 *
 * Return: number of bits that was needed to be flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m, b = 0;

	while (xor > 0)
	{
		b += (xor & 1);
		xor >>= 1;
	}

	return (b);
}
