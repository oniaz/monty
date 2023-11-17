#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/* Structs */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* change this back to stack_s when done!!!*/

/* External Variables */
extern unsigned int lineCount;
extern char **instructions_array;
extern char *lineBuffer;
extern stack_t *top;
extern stack_t *bottom;

/* Function Parameters */

/* tests */
void printTest(void);

/* file/line reading */
int wordCounter(char *str);
void tokenize(void);
void MontyLineReader(char *monty_path);

/* free and exit */
void freeInstructionsArray(void);

/* misc */
int isNumber(char *str);
void (*getFunc(char *s))(stack_t **stack, unsigned int line_number);

/* instruction operations */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif
