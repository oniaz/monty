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
