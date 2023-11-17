#include "monty.h"

/**
 * wordCounter - counts slices in a given string
 * @str: the given string
 *
 * Return: number of slices in the string
 */
int wordCounter(char *str)
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

/**
 * tokenize - slices given string and puts slices in an array
 *
 * Return: nothing
 */
void tokenize(void)
{
	int counter = wordCounter(lineBuffer);
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

/**
 * MontyLineReader - checks if a filepath is valid, if valid proceeds to
 * read it lineby line
 * @monty_path: path to the monty file
 *
 * Return: nothing
 */
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
			if (instructions_array)/* not all spaces*/
			{
				getFunc(instructions_array[0])(&top, lineCount);
				freeInstructionsArray();
			}
		}
	}
	free(lineBuffer);
	fclose(file);
}
