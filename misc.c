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
