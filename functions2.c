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
 * sub - subtracts the top element of the stack from the second
 * top element of the stack.
 *
 * Return: nothing.
 */
void sub(void)
{
	if (!top || !top->prev)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", lineCount);
		exit(EXIT_FAILURE);
	}
	top->prev->n -= top->n;
	pop();
}

/**
 * divide - divides the second top element of the stack by the
 * top element of the stack.
 *
 * Return: nothing.
 */
void divide(void)
{
	if (!top || !top->prev)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", lineCount);
		exit(EXIT_FAILURE);
	}
	if (!top->n) /* is zero */
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", lineCount);
		exit(EXIT_FAILURE);	
	}
	top->prev->n /= top->n;
	pop();
}

/**
 * mul - divides the second top element of the stack by the
 * top element of the stack.
 *
 * Return: nothing.
 */
void mul(void)
{
	if (!top || !top->prev)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", lineCount);
		exit(EXIT_FAILURE);
	}

	top->prev->n *= top->n;
	pop();
}

/**
 * div - divides the second top element of the stack by the
 * top element of the stack.
 *
 * Return: nothing.
 */
void mod(void)
{
	if (!top || !top->prev)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", lineCount);
		exit(EXIT_FAILURE);
	}
	if (!top->n) /* is zero */
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", lineCount);
		exit(EXIT_FAILURE);	
	}
	top->prev->n %= top->n;
	pop();
}
