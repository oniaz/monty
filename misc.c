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
 * @n: value to be checked.
 *
 * Return: 1 if it's in the ascii table, 0 if not.
 */
int isAscii(int n)
{
	if (n < 0 || n > 127)
		return (0);
	return (1);
}

/**
 * getBottom - prints the value of the bottom stack item.
 *
 * Return: nothing
 */
void getBottom(void)
{
	if (bottom)
		dprintf(STDOUT_FILENO, "bottom: %d\n", bottom->n);

	if (bottom->next)
		dprintf(STDOUT_FILENO, "bottom->next: %d\n", bottom->next->n);
}

/**
 * pline - prints a line of asterisks.
 *
 * Return: nothing
 */
void pline(void)
{
	dprintf(STDOUT_FILENO, "************\n");
}
