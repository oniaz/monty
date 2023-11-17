#include "monty.h"

/**
 * freeInstructionsArray - frees the buffer carrying the
 * instruction and arguments
 *
 * Return: nothing
 */
void freeInstructionsArray(void)
{
	int i = 0;

	if (!montyLine)
		return;

	while (montyLine[i])
	{
		free(montyLine[i]);
		montyLine[i] = NULL;
		i++;
	}
	free(montyLine);
	montyLine = NULL;
}

/**
 * freeStack - frees the stack.
 *
 * Return: nothing.
 */
void freeStack(void)
{
	pile_t *newTop;

	while (top)
	{
		newTop = top->prev;
		free(top);
		top = newTop;
	}
}
