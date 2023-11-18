#include "monty.h"

/**
 * nop - doesn’t do anything.
 *
 * Return: nothing.
 */
void nop(void)
{
	/* I'm super lazy and this works, so why not ?*/
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 *
 * Return: nothing.
 */
void pchar(void)
{
	if (!top)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", lineCount);
		exit(EXIT_FAILURE);
	}
	if (top->n < 0 || top->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", lineCount);
		exit(EXIT_FAILURE);
	}

	dprintf(STDOUT_FILENO, "%c\n", top->n);
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 *
 * Return: nothing.
 */
void pstr(void)
{
	pile_t *ptr = top;

	while (ptr && ptr->n && isAscii(ptr->n))
	{
		dprintf(STDOUT_FILENO, "%c", ptr->n);
		ptr = ptr->prev;
	}
	dprintf(STDOUT_FILENO, "\n");
}

/**
 * rotl - moves the top item of the stack to the bottom.
 *
 * Return: nothing.
 */
void rotl(void)
{
	if (bottom && top != bottom)
	{
		pile_t *tmp = top->prev;

		top->next = bottom;
		top->prev = NULL;
		bottom->prev = top;
		bottom = top;
		top = tmp;
		top->next = NULL;
	}
}

/**
 * rotr - moves the bottom item of the stack to the top.
 *
 * Return: nothing.
 */
void rotr(void)
{
	if (bottom && top != bottom)
	{
		pile_t *tmp = bottom->next;

		bottom->prev = top;
		bottom->next = NULL;
		top->next = bottom;
		top = bottom;
		bottom = tmp;
		bottom->prev = NULL;
		bottom->next = tmp->next;
	}
}
