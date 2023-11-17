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

	if (!instructionsArray)
		return;

	while (instructionsArray[i])
	{
		free(instructionsArray[i]);
		instructionsArray[i] = NULL;
		i++;
	}
	free(instructionsArray);
	instructionsArray = NULL;
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
