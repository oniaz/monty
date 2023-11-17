#include "monty.h"

int main(int argc, char **argv);
unsigned int lineCount = 0;
char **instructionsArray = NULL;
char *lineBuffer = NULL;
pile_t *top = NULL;
pile_t *bottom = NULL;

/**
 * main - checks number of arguemnts,
 * if correct sends the filepath to to be read
 * @argc: number of argumnets
 * @argv: vector of arguments
 * Return: 0 for success.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	MontyLineReader(argv[1]);
	freeStack();
	return (0);
}
