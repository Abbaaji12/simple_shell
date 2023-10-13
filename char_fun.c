#include "shell.h"

/**
 * _putchar - Custom function to write a single character to stdout
 * @c: The character to be printed
 *
 * This function writes the character 'c' to the standard output (stdout).
 *
 * Return: On success, 1 is returned, and the character is printed.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strncpy - copy of  a string
 * @dest:Char.
 *  @src:Char.
 * @n:int.
 * Return:Char.
 */

char *_strncpy(char *dest, char *src, int n)
{
int i;

i = 0;
	while (i < n && *(src + i))
	{
	*(dest + i) = *(src + i);
	i++;
	}
	while (i < n)
	{
	*(dest + i) = '\0';
	i++;
	}
	return (dest);
}

/**
 * _strlen - Lenght of the strings
 * @s:Char.
 * Return:Int if success
 */

int _strlen(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}

/**
 * _atoi - convert to a int
 * @s:string
 * Return:int
 */
int _atoi(char *s)
{
int i, g, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	g = i;
	while ((s[g] >= '0') && (s[g] <= '9'))
	{
		n = (n * 10) + x * ((s[g]) - '0');
		g++;
	}
	return (n);
}
/**
 * _puts - Print a the string
 * @str:Pointer Char
 * return:Void.
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
_putchar('\n');
return;
}
