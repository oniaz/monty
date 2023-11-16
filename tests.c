#include "monty.h"

void printTest(void)
{
	int i = 0;
	printf("Line [%u]:\n", lineCount);
	if (!instructions_array)
	{
		printf("array null, when the heck does this even happen? yes when empty line all spaces do nothing\n");
		return;
	}
	while (instructions_array[i])
	{
		printf("arg %d: %s|\n", i, instructions_array[i]);
		i++;
	}
	printf("-----\n");
}
