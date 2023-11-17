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

	if (!montyLine[1] || !isNumber(montyLine[1]))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", lineCount);
		exit(EXIT_FAILURE);
	}
	value = atoi(montyLine[1]);

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

/**
 * pint - prints the value at the top of the stack.
 *
 * Return: nothing
 */
void pint(void)
{
	if (!top)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", lineCount);
		exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%d\n", top->n);

}

/**
 * pop - removes the top element of the stack.
 *
 * Return: nothing
 */
void pop(void)
{
	pile_t *newTop = top;

	if (!top)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", lineCount);
		exit(EXIT_FAILURE);
	}
	newTop = top->prev;
	free(top);
	top = newTop;
}
