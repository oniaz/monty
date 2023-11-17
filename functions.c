#include "monty.h"

/**
 * push - adds a new stack element.
 *
 * Return: nothing
 */
void push(void)
{
	pile_t *s_item;
	int value;

	if (!instructionsArray[1] || !isNumber(instructionsArray[1]))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", lineCount);
		exit(EXIT_FAILURE);
	}
	value = atoi(instructionsArray[1]);

	s_item = malloc(sizeof(pile_t));
	if (!s_item)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	} /*failed to allocate*/
	if (!bottom)
		bottom = s_item;

	s_item->n = value;
	s_item->next = NULL;
	s_item->prev = top;
	top = s_item;
}

/**
 * pall - prints the stack from starting from the top element.
 *
 * Return: nothing
 */
void pall(void)
{
	pile_t *ptr = top;

	while (ptr)
	{
		dprintf(STDOUT_FILENO, "%d\n", ptr->n);
		ptr = ptr->prev;
	}
}
