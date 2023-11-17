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

	instruction_t inst_op[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};

	while (inst_op[i].opcode != NULL && strcmp((inst_op[i].opcode), str) != 0)
		i++;
	if (!inst_op[i].opcode)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", lineCount, str);
		exit(EXIT_FAILURE);
	}
	return (inst_op[i].f);
}
