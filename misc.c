#include "monty.h"

/**
 * isNumber - checks if  agiven string is a number
 * @str: string to be checked
 * Return: 1 if it's a number, 0 if not a number or empty string
 */
int isNumber(char *str)
{
	if (*str == '\0')
		return (0);

	if (*str == '-')
		++str;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		++str;
	}
	return (1);
}

/**
 * isAscii - checks if a given value is in the ascii table.
 * @c: value to be checked.
 *
 * Return: 1 if it's in the ascii table, 0 if not.
 */
int isAscii(char c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}
