#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/* Structs */

/**
 * struct pile_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct pile_s
{
	int n;
	struct pile_s *prev;
	struct pile_s *next;
} pile_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(void);
} instruction_t;

/* change this back to stack_s when done!!!*/

/* External Variables */
extern unsigned int lineCount;
extern char **montyLine;
extern char *lineBuffer;
extern pile_t *top;
extern pile_t *bottom;

/* Function Parameters */

/* tests */
void printTest(void);

/* file/line reading */
int wordCounter(char *str);
void tokenize(void);
void MontyLineReader(char *monty_path);

/* free and exit */
void freeInstructionsArray(void);
void freeStack(void);
/* need to free line buffer, instructionsarray, s t a c k */

/* misc */
int isNumber(char *str);
void (*getFunc(char *s))(void);

/* instruction operations */
void push(void);
void pall(void);
void pint(void);
void pop(void);
void swap(void);
void add(void);
void sub(void);
void nop(void);

#endif
