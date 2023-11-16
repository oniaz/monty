#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

extern unsigned int lineCount;
extern char **instructions_array;
extern char *lineBuffer;

/* tests */
/*void printTest(void); */

/* line */
int _wordcounter(char *str);
void tokenize(void);
void MontyLineReader(char *monty_path);

/* free */
void freeInstructionsArray(void);

#endif
