#include <stdio.h>

void premain(void) __attribute__ ((constructor));

/**
 * premain - prints a sentence before the main.
 * function is executed.
 */
void premain(void)
{
	printf("You're beeat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
