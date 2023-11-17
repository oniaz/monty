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

	instructionsArray = malloc(sizeof(char *) * (counter + 1));
	if (!instructionsArray)
		return; /* memory allocation failure */
	token = strtok(lineBuffer, delimiter);

	while (token != NULL)
	{
		(instructionsArray)[i] = (char *)malloc(strlen(token) + 1);
		done++;
		if (!(instructionsArray)[i]) /* memory allocation failure */
		{
			while (done)
			{
				free((instructionsArray)[done - 1]);
				(instructionsArray)[done - 1] = NULL;
				done--;
			}
			free(instructionsArray);
			(instructionsArray) = NULL;
			return;
		}
		strcpy((instructionsArray)[i], token);
		i++;
		token = strtok(NULL, delimiter);
	}
	(instructionsArray)[counter] = NULL;
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
			if (instructionsArray)/* not all spaces*/
			{
				getFunc(instructionsArray[0])();
				freeInstructionsArray();
			}
		}
	}
	free(lineBuffer);
	fclose(file);
}
