#include "monty.h"

unsigned int lineCount = 0; /* make global */
char **instructions_array = NULL;
char *lineBuffer = NULL;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	MontyLineReader(argv[1]);
	return (0);
}
