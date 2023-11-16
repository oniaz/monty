#include "monty.h"

int _wordcounter(char *str)
{
    int flag, c;

    if (str == NULL)
        return (0);
    flag = 0;
    c = 0;
    while (*str != '\0' && *str != '\n')
    {
        if (flag == 0 && *str != ' ')
        {
            c++;
            flag = 1;
        }
        else if (flag == 1 && *str == ' ')
            flag = 0;
        str++;
    }
    return (c);
}

void tokenize(void)
{
    int counter = _wordcounter(lineBuffer);
    int i = 0, done = 0;
    char *token;
    const char *delimiter = " \n";

    if (counter == 0)
        return;

    instructions_array = malloc(sizeof(char *) * (counter + 1));
    if (!instructions_array)
        return; /* memory allocation failure */
    token = strtok(lineBuffer, delimiter);

    while (token != NULL)
    {
        (instructions_array)[i] = (char *)malloc(strlen(token) + 1);
        done++;
        if (!(instructions_array)[i]) /* memory allocation failure */
        {
            while (done)
            {
                free((instructions_array)[done - 1]);
                (instructions_array)[done - 1] = NULL;
                done--;
            }
            free(instructions_array);
            (instructions_array) = NULL;
            return;
        }
        strcpy((instructions_array)[i], token);
        i++;
        token = strtok(NULL, delimiter);
    }
    (instructions_array)[counter] = NULL;
}

void MontyLineReader(char *monty_path)
{
    FILE *file;
    size_t bufferSize = 0;
    ssize_t read;

    file = fopen(monty_path, "r");
    if (!file)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", monty_path);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&lineBuffer, &bufferSize, file)) != -1)
    {
        lineCount++;
        if (read > 1) /* not a new line */
        {
            tokenize();
            printTest();
            /* do stuff */
            freeInstructionsArray();
        }
    }
    free(lineBuffer);
    fclose(file);
}
