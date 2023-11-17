#include "monty.h"

/**
 * getFunc - retrieves the appropriate function for the given instruction.
 * @str: the instruction.
 *
 * Return: pointer to the instruction function.
 */
void (*getFunc(char *str))(void)
{
	int i = 0;

	instruction_t instructionsMenu[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}};

	while (instructionsMenu[i].opcode != NULL &&
			strcmp((instructionsMenu[i].opcode), str) != 0)
		i++;
	if (!instructionsMenu[i].opcode)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lineCount, str);
		exit(EXIT_FAILURE);
	}
	return (instructionsMenu[i].f);
}
