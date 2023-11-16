#include "monty.h"

void freeInstructionsArray(void)
{
    int i = 0;

    if (!instructions_array)
        return;

    while (instructions_array[i])
    {
        free(instructions_array[i]);
        instructions_array[i] = NULL;
        i++;
    }
    free(instructions_array);
    instructions_array = NULL;
}
