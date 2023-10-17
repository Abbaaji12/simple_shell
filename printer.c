#include "shell.h"

/**
 * print_number - Print Unsigned Int using putchar
 * @n: Unsigned Integer
 * Return: Void
 */

void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_number_in - Print Integer using putchar
 * @n: Integer
 * Return: Void
 */
void print_number_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
