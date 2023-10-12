#include "shell.h"
/**
 * check_delim - to Checks If A Char Match Any Char *
 * @c: A Char To Check
 * @str: A Str To Check
 * Return: on Succes it return 1, when it Fail it return 0
 */
unsigned int check_delim(char c, const char *str) /* delim declration */
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++) /* loop to check for delimeter */
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - Token A String Into Token (strtok)
 * @str: String
 * @delim: Delim
 * Return: Ptr To The Next Token Or NULL
 */
char *_strtok(char *str, const char *delim) /* strtok (string tokinization */
{
	static char *ts;
	static char *nt;
	unsigned int i;

	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (i = 0; ts[i] != '\0'; i++)
	{
		if (check_delim(ts[i], delim) == 0)
			break;
	}
	if (nt[i] == '\0' || nt[i] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + i;
	nt = ts;
	for (i = 0; nt[i] != '\0'; i++)
	{
		if (check_delim(nt[i], delim) == 1)
			break;
	}
	if (nt[i] == '\0')
		nt = NULL;
	else
	{
		nt[i] = '\0';
		nt = nt + i + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}
