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

	if (!instructions_array)
		return;

	while (instructions_array[i])
	{
		free(instructions_array[i]);
		instructions_array[i] = NULL;
		i++;
	}
	free(instructions_array);
	instructions_array = NULL;
}

/**
 * freeStack - frees the stack.
 *
 * Return: nothing.
 */
void freeStack(void)
{
	bingo_t *next;

	while (top)
	{
		next = top->next;
		free(top);
		top = next;
	}
}
