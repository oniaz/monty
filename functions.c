#include "monty.h"

/**
 * push - adds a new stack element.
 * @stackTop: double pointer to the stack's top element.
 * @lineNumber: current instruction line in the monty file.
 *
 * Return: nothing
 */
void push(bigno_t **stackTop, unsigned int lineNumber)
{
	bigno_t *s_item;
	int value;

	if (!instructions_array[1] || !isNumber(instructions_array[1]))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	value = atoi(instructions_array[1]);

	s_item = malloc(sizeof(bigno_t));
	if (!s_item)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	} /*failed to allocate*/
	if (!bottom)
		bottom = s_item;

	s_item->n = value;
	s_item->next = NULL;
	s_item->prev = *stackTop;
	*stackTop = s_item;
}

/**
 * pall - pritns the stack from starting from the top element.
 * @stackTop: double pointer to the stack's top element.
 * @lineNumber: current instruction line in the monty file.
 *
 * Return: nothing
 */
void pall(bigno_t **stackTop, unsigned int lineNumber)
{
	bigno_t *ptr = *stackTop;

	(void)lineNumber;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->prev;
	}
}
