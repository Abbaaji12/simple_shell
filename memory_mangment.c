#include "shell.h"

/**
 * _realloc - Reallocate Memory Block with Malloc and Free
 * @ptr: Pointer
 * @old_size: Previous Size
 * @new_size: New Size
 * Return: Void Pointer (Reallocated Memory)
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);

}
/**
 * free_all - Free Array of Char Pointers and Char Pointer
 * @cmd: Array Pointer
 * @line: Char Pointer
 * Return: Void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}
/**
 * _memcpy - Copy Bytes from Source to Destination
 * @dest: Destination Pointer
 * @src: Source Pointer
 * @n: Size to copy
 * Return: Void Pointer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * fill_an_array - Fill an Array with a Constant Byte
 * @a: Void Pointer
 * @el: Integer
 * @len: Length of the Array
 * Return: Void Pointer
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _calloc - Allocate Memory for an Array using Malloc
 * @size: Size
 * Return: Void Pointer
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
