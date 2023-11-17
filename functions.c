#include "monty.h"

/**
 * push - adds a new bingo element.
 * @bingoTop: double pointer to the bingo's top element.
 * @lineNumber: current instruction line in the monty file.
 *
 * Return: nothing
 */
void push(void)
{
	bingo_t *s_item;
	int value;

	if (!instructions_array[1] || !isNumber(instructions_array[1]))
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", lineCount);
		exit(EXIT_FAILURE);
	}
	value = atoi(instructions_array[1]);

	s_item = malloc(sizeof(bingo_t));
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
 * pall - pritns the bingo from starting from the top element.
 * @bingoTop: double pointer to the bingo's top element.
 * @lineNumber: current instruction line in the monty file.
 *
 * Return: nothing
 */
void pall(void)
{
	bingo_t *ptr = top;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->prev;
	}
}
