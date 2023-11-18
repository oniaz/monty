#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 *
 * Return: nothing.
 */
void add(void)
{
	if (!top || !top->prev)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", lineCount);
		exit(EXIT_FAILURE);
	}
	top->prev->n += top->n;
	pop();
}

/**
 * nop - doesn’t do anything.
 *
 * Return: nothing.
 */
void nop(void)
{
	/* I'm super lazy and this works, so why not ?*/
}
